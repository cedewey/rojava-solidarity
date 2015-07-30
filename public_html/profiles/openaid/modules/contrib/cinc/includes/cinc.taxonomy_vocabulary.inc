<?php

/**
* Creates vocabs in code.
*
* @code
* $vocab = CINC::init('TaxonomyVocabulary');
* @endcode
*/
class CINC_TaxonomyVocabulary extends CINC implements CINC_CRUD {

  public $config_machine_name = 'machine_name';

  function __construct() {

    $this->config_filters['machine_name'] = 'set_machine_name';

    // Set defaults.

    $this->config = array(
      'machine_name' => '',
      'name' => '',
      'base' => 'node_content',
      'description' => '',
      'help' => '',
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
      'disabled' => 0,
      'is_new' => 1,
      'title_label' => 'Title',
    );

    $this->original_config = $this->config;

    return $this;

  }

  /**
   * Auto-adds name when type is set, and cleans type.
   */
  public function set_machine_name($type) {
    if (empty($this->config['name'])) {
      $this->set('name', CINC::display_name_from_machine_name($type));
    }
    return CINC::clean_machine_name($type);
  }

  /**
  * Saves vocab to the database.
  */
  public function create() {
    taxonomy_vocabulary_save((object) $this->config);
    return $this;
  }

  /**
   * Tests if vocab exists.
   */
  public function exists() {
    $taxonomy = taxonomy_vocabulary_machine_name_load($this->get('machine_name'));
    if ($taxonomy) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
  * Loads vocab from the database.
  */
  public function read() {
    $taxonomy = taxonomy_vocabulary_machine_name_load($this->get('machine_name'));
    if ($taxonomy) {
      $this->config = (array) $taxonomy;
    }
    return $this;
  }

  /**
  * Saves vocab to the database.
  */
  public function update() {
    // $this->create();
    taxonomy_taxonomy_vocabulary_update((object) $this->config);
    return $this;
  }

  /**
  * Removes vocab from the database.
  */
  public function delete() {
    $taxonomy_vocabulary = taxonomy_vocabulary_machine_name_load($this->config[$this->config_machine_name]);
    taxonomy_vocabulary_delete($taxonomy_vocabulary->vid);
    return $this;
  }

  public function add_field($field, $weight = NULL) {
    if (!($field instanceof CINC_Field)) {
      if ($field instanceof CINC_MissingDependencies) {
        $dependencies = implode(', ', $field->missing_dependencies);
        drupal_set_message(t('CINC_TaxonomyVocabulary::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), 'warning');
        watchdog('CINC', format_string('CINC_TaxonomyVocabulary::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), array(), WATCHDOG_WARNING);
      }
      else {
        throw new Exception('CINC_TaxonomyVocabulary::add_field requires a CINC_Field instance as the first parameter');
      }
    }
    else {
      // Use the CINC_Field Class method to save the field to this vocabulary.
      $field->create_instance_for('taxonomy_vocabulary', $this->config['machine_name'], $weight);
    }

    // Add this field to the fields array property.
    if ($is_saved) {
      array_push($field, $this->fields);
    }

    return $this;
  }

}
