<?php

/**
 * Creates menus in code.
 *
 * @code
 * $menu = CINC::init('Menu')->set('menu_name', 'my_menu');
 * @endcode
 */
class CINC_Menu extends CINC implements CINC_CRUD {

  public static $dependencies = array('menu');
  public $config_machine_name = 'menu_name';
  public $cinc_yaml_prefix = 'system.menu';
  public $links = array();

  function __construct() {

    $this->config_filters['menu_name'] = 'set_menu_name';

  	$this->config = array(
      'menu_name' => '',
      'title' => '',
      'description' => '',
		);

  }

  /**
   * Auto-adds title when menu_name is set, and cleans menu_name.
   */
  public function set_menu_name(&$menu_name) {
    $menu_name = CINC::clean_machine_name($menu_name);
    if (empty($this->config['title'])) {
      $this->set('title', CINC::display_name_from_machine_name($menu_name));
    }
    return TRUE;
  }

  /**
   * Saves menu to the database.
   */
  public function create() {
    menu_save($this->config);
    return $this;
  }

  /**
   * Tests if content type exists.
   */
  public function exists() {
    $menu = menu_load($this->config['menu_name']);
    if ($menu) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Loads menu from the database.
   */
  public function read() {
    $read_success = FALSE;
    $menu = menu_load($this->config['menu_name']);
    if ($menu) {
      $this->config = $menu;
      $this->read_success = TRUE;
      $this->links = menu_load_links($this->config['menu_name']);
    }
    return $this;
  }

  /**
   * Loads list of machine names.
   */
  static public function read_list() {

    $list = array();

    $menus = menu_load_all();

    foreach ($menus as $machine_name => $menu) {
      $list[$machine_name] = array(
        'display' => $menu['title'],
      );
    }

    return $list;

  }

  public function get_links_as_tree() {
    return menu_tree_data($this->links);
  }

  public function get_link_by_property($property, $value) {

    foreach ($this->links as $link) {
      if ($link[$property] == $value) {
        return $link;
      }
    }

  }

  /**
   * Saves menu to the database and migrates previous data if machine name changed.
   */
  public function update() {
    $this->create();
    return $this;
  }

  /**
   * Removes menu from the database.
   */
  public function delete() {
    menu_delete($this->config);
    return $this;
  }

}
