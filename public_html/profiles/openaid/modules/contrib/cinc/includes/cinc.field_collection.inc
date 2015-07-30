<?php

/**
 * Creates field collections in code.
 *
 * @code
 * $field_collection = CINC::init('FieldCollection')->set('field_name', 'field_my_field');
 * @endcode
 */
class CINC_FieldCollection extends CINC implements CINC_CRUD {

  public static $dependencies = array('field_collection');
  public $config_machine_name = 'field_name';

  function __construct() {

    $this->config_filters['field_name'] = 'set_field_name';

  	$this->config = array(
      'field_name' => '',
      'bundle' => '',
      'fields' => array(),
      'entity_type' => 'node',
      'fields' => array(
        'field_name' => '',
      ),
		);

  }

  /**
   * Cleans field name and auto-sets fields[field_name].
   */
  public function set_field_name(&$field_name) {
    $field_name = CINC::clean_machine_name($field_name);
    $this->set('fields', array(
      'field_name' => $field_name
    ));
    return TRUE;
  }

  /**
   * Saves field collection to the database.
   */
  public function create() {
    $field_collection = entity_create('field_collection_item', $this->config['fields']);
    $field_collection->setHostEntity($this->config['entity_type'], node_type_load($this->config['bundle']));
    $field_collection->save(TRUE);

    return $this;
  }

  /**
   * Tests if content type exists.
   * TODO: make this do something?
   */
  public function exists() {
    return TRUE;
  }

  /**
   * Loads field collection from the database.
   */
  public function read() {
    $this->read_success = TRUE;
    return $this;
  }

  /**
   * Saves field collection to the database and migrates previous data if machine name changed.
   */
  public function update() {
    $this->create();
    return $this;
  }

  /**
   * Removes field collection from the database.
   */
  public function delete() {
    return $this;
  }


  /**
   * Adds field (instance) to the field collection.
   *
   * @param CINC_Field $field_instance
   *
   * @return $this
   */
  public function add_field($field, $weight = NULL) {
    if (!($field instanceof CINC_Field)) {
      if ($field instanceof CINC_MissingDependencies) {
        $dependencies = implode(', ', $field->missing_dependencies);
        drupal_set_message(t('CINC_FieldCollection::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), 'warning');
        watchdog('CINC', format_string('CINC_FieldCollection::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), array(), WATCHDOG_WARNING);
      }
      else {
        throw new Exception('CINC_FieldCollection::add_field requires a CINC_Field instance as the first parameter');
      }
    }
    else {
      // Use the CINC_Field Class method to save the field to this field collection.
      $field->create_instance_for('field_collection_item', $this->config['field_name'], $weight);
    }

    return $this;
  }


}
