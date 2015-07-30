<?php
/**
 * @file
 * openaid_dashboard_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function openaid_dashboard_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-dashboard-links.
  $menus['menu-dashboard-links'] = array(
    'menu_name' => 'menu-dashboard-links',
    'title' => 'Dashboard Links',
    'description' => 'Provides custom links to the dashboard.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard Links');
  t('Provides custom links to the dashboard.');


  return $menus;
}
