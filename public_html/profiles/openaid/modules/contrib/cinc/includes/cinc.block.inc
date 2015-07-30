<?php

/**
 * Creates blocks in code.
 *
 * @code
 * $my_block = CINC::init('Block')->machine_name('system:main-menu')->read();
 * @endcode
 */
class CINC_Block extends CINC implements CINC_CRUD {

  public static $dependencies = array('block');
  public $config_machine_name = 'module_delta';
  public $cinc_yaml_prefix = 'block';

  function __construct() {

    $this->config_filters['module_delta'] = 'set_module_delta';

    $this->config = array(
      'module' => 'system',
      'delta' => '',
      'title' => '',
      'visibility' => '',
      'pages' => '',
      'custom' => '',
    );

  }

  /**
   * Sets module and delta on module_delta.
   */
  public function set_module_delta(&$module_delta) {

    list($module, $delta) = explode(':', $module_delta);

    $this->set('module', $module);
    $this->set('delta', $delta);

    return FALSE;

  }

  /**
   * Saves block to the database.
   */
  public function create() {
    return $this;
  }

  /**
   * Tests if block exists.
   */
  public function exists() {
    $block = block_load($this->get('module'), $this->get('delta'));
    if (isset($block->bid)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Loads block from the database.
   */
  public function read() {

    $this->config = (array) block_load($this->get('module'), $this->get('delta'));
    return $this;

  }

  /**
   * Loads list of machine names.
   */
  static public function read_list() {

    $list = array();
    return $list;

  }

  /**
   * Saves block to the database.
   */
  public function update() {

    db_update('block')
      ->fields(array(
        'visibility' => (int) $this->get('visibility'),
        'pages' => trim($this->get('pages')),
        'custom' => (int) $this->get('custom'),
        'title' => $this->get('title'),
      ))
      ->condition('module', $this->get('module'))
      ->condition('delta', $this->get('delta'))
      ->execute();

    return $this;
  }

  /**
   * Removes block from the database.
   */
  public function delete() {
    return $this;
  }

}
