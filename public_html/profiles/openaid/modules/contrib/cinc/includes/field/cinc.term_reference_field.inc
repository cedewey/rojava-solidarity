<?php

/**
 * Creates term reference fields that can be saved to content types.
 *
 * @code
 * $my_field = CINC::init('TermReferenceField')->set('field_name', 'field_my_field');
 * @endcode
 */
class CINC_TermReferenceField extends CINC_Field {

  public static $dependencies = array('field', 'taxonomy');
  public static $field_types = array('taxonomy_term_reference');

  function __construct() {

    parent::__construct();

    $this
      ->set('type', 'taxonomy_term_reference')
      ->set('module', 'taxonomy')
      ->set('settings', array(
        'allowed_values' => array(),
      ))
      ->set_instance('widget', array(
        'type' => 'options_select',
        'module' => 'options'
      ));

  }

  function allow_vocab($vocab) {
    if (!isset($this->config['settings']['allowed_values'])) {
      $this->config['settings']['allowed_values'] = array();
    }

    $this->config['settings']['allowed_values'][] = array(
      'vocabulary' => $vocab,
      'parent' => 0,
    );

    return $this;
  }

}