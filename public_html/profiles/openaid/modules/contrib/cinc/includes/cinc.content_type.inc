<?php

/**
 * Creates content types in code.
 *
 * @code
 * $content_type = CINC::init('ContentType')->set('type', 'my_content_type');
 * @endcode
 */
class CINC_ContentType extends CINC implements CINC_CRUD {

  public $config_machine_name = 'type';
  public $cinc_yaml_prefix = 'node.type';
  public $original_config = array();
  public $fields = array();

  function __construct() {

    $this->config_filters['type'] = 'set_type';

    // Set defaults.

    $this->config = array(
      'type' => '',
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
      'submitted' => TRUE,
      'comment' => 0,
      'comment_options' => array(
        'default_mode' => 0,
        'default_per_page' => 50,
        'anonymous' => 2,
        'subject_field' => 0,
        'preview' => 0,
        'form_location' => 1,
      ),
      'path_auto' => '',
      'node_options' => array(),
      'workbench_moderation_default_state' => '',
    );

    $this->original_config = $this->config;

    return $this;

  }

  /**
   * Auto-adds name when type is set, and cleans type.
   */
  public function set_type(&$type) {
    $type = CINC::clean_machine_name($type);
    if (empty($this->config['name'])) {
      $this->set('name', CINC::display_name_from_machine_name($type));
    }
    return TRUE;
  }

  /**
   * Saves the content type to the database.
   *
   * @code
   * new CINC_ContentType('my_content_type')
   *   ->save();
   * @endcode
   */
  public function create() {
    $content_type = node_type_set_defaults($this->config);
    node_type_save($content_type);
    $this->set_variables();

    return $this;
  }

  /**
   * Tests if content type exists.
   */
  public function exists() {
    $type = node_type_load($this->config['type']);
    if ($type) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Loads content type information from the database.
   */
  public function read() {
    $type = node_type_load($this->config['type']);
    $this->read_success = FALSE;
    if ($type !== FALSE) {
      $this->read_success = TRUE;
      $this->config = (array) $type;
      $this->get_variables();
    }

    return $this;
  }

  /**
   * Loads field information from the database.
   */
  public function read_fields() {
    $this->fields = array();
    $field_instances = field_info_instances('node', $this->get('type'));

    foreach ($field_instances as $field_instance) {
      $field = CINC::init('Field')->machine_name($field_instance['field_name'])->read();
      $field->instance = CINC::init('FieldInstance');
      $field->instance->config = $field_instance;
      $this->fields[] = $field;
    }

    return $this;
  }

  /**
   * Loads list of machine names.
   */
  static public function read_list() {

    $list = array();

    $types = node_type_get_types();

    foreach ($types as $machine_name => $type) {
      $list[$machine_name] = array(
        'display' => $type->name,
      );
    }

    return $list;

  }

  /**
   * Saves content type to the database and migrates previous if machine name changed.
   */
  public function update() {
    $this->create();

    if ($this->config['type'] != $this->original_config['type']) {
      $original = new CINC_ContentType($this->original_config['type']);
      $original->read()->delete();
    }

    $this->set_variables();

    return $this;
  }


  /**
   * Write type settings to variable table.
   */
  private function set_variables() {
    if (module_exists('comment')) {
      variable_set('comment_' . $this->get('type'), $this->get('comment'));
      variable_set('comment_default_mode_' . $this->get('type'), $this->get('comment_options.default_mode'));
      variable_set('comment_default_per_page_' . $this->get('type'), $this->get('comment_options.default_per_page'));
      variable_set('comment_anonymous_' . $this->get('type'), $this->get('comment_options.anonymous'));
      variable_set('comment_subject_field_' . $this->get('type'), $this->get('comment_options.subject_field'));
      variable_set('comment_preview_' . $this->get('type'), $this->get('comment_options.preview'));
      variable_set('comment_form_location_' . $this->get('type'), $this->get('comment_options.form_location'));
    }
    if (module_exists('pathauto')) {
      variable_set('pathauto_node_' . $this->get('type') . '_pattern', $this->get('pathauto'));
    }
    if (module_exists('workbench_moderation')) {
      variable_set('workbench_moderation_default_state_' . $this->get('type'), $this->get('workbench_moderation_default_state'));
    }
    variable_set('node_submitted_' . $this->get('type'), $this->get('submitted'));
    variable_set('node_preview_' . $this->get('type'), $this->get('preview'));
    variable_set('node_options_' . $this->get('type'), $this->get('node_options'));

  }

  /**
   * Get type settings from variable table.
   */
  private function get_variables() {
    if (module_exists('comment')) {
      $this->set('comment', variable_get('comment_' . $this->get('type')));
      $this->set('comment_options.default_mode', variable_get('comment_default_mode_' . $this->get('type')));
      $this->set('comment_options.default_per_page', variable_get('comment_default_per_page_' . $this->get('type')));
      $this->set('comment_options.anonymous', variable_get('comment_anonymous_' . $this->get('type')));
      $this->set('comment_options.subject_field', variable_get('comment_subject_field_' . $this->get('type')));
      $this->set('comment_options.preview', variable_get('comment_preview_' . $this->get('type')));
      $this->set('comment_options.form_location', variable_get('comment_form_location_' . $this->get('type')));
    }
    if (module_exists('pathauto')) {
      $this->set('pathauto', variable_get('pathauto_node_' . $this->get('type') . '_pattern', ''));
    }
    if (module_exists('workbench_moderation')) {
      $this->set('workbench_moderation_default_state', variable_get('workbench_moderation_default_state_' . $this->get('type')));
    }
    $this->set('submitted', variable_get('node_submitted_' . $this->get('type'), ''));
    $this->set('preview', variable_get('node_preview_' . $this->get('type'), ''));
    $this->set('node_options', variable_get('node_options_' . $this->get('type'), array()));
  }

  /**
   * Removes content type from the database.
   */
  public function delete() {
    node_type_delete($this->config['type']);

    return $this;
  }

  /**
   * Adds field (instance) to the content type.
   *
   * @param CINC_Field $field_instance
   *
   * @return $this
   */
  public function add_field($field, $weight = NULL) {
    if (!($field instanceof CINC_Field)) {
      if ($field instanceof CINC_MissingDependencies) {
        $dependencies = implode(', ', $field->missing_dependencies);
        drupal_set_message(t('CINC_ContentType::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), 'warning');
        watchdog('CINC', format_string('CINC_ContentType::add_field tried to add field @field_name but is missing dependencies: @dependencies', array('@field_name' => $field->config['field_name'], '@dependencies' => $dependencies)), array(), WATCHDOG_WARNING);
      }
      else {
        throw new Exception('CINC_ContentType::add_field requires a CINC_Field instance as the first parameter');
      }
    }
    else {
      // Use the CINC_Field Class method to save the field to this content type.
      $field->create_instance_for('node', $this->config['type'], $weight);
    }

    // Add this field to the fields array property.
    if ($is_saved) {
      array_push($field, $this->fields);
    }

    return $this;
  }

}
