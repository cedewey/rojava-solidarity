<?php
/**
 * @file
 * openaid_dashboard_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function openaid_dashboard_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-dashboard-links_add-content:node/add
  $menu_links['menu-dashboard-links_add-content:node/add'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_add-content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_add-media-images-audio-video:admin/content/file
  $menu_links['menu-dashboard-links_add-media-images-audio-video:admin/content/file'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/content/file',
    'router_path' => 'admin/content',
    'link_title' => 'Add Media (images, audio, video)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_add-media-images-audio-video:admin/content/file',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_additional-openaid-settings:admin/config/atom
  $menu_links['menu-dashboard-links_additional-openaid-settings:admin/config/atom'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/config/atom',
    'router_path' => 'admin/config',
    'link_title' => 'Additional OpenAid Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_additional-openaid-settings:admin/config/atom',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_edit-content:admin/content
  $menu_links['menu-dashboard-links_edit-content:admin/content'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Edit Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_edit-content:admin/content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_edit-site-appearance-colors-logo-copyright:admin/appearance/settings/openaid2
  $menu_links['menu-dashboard-links_edit-site-appearance-colors-logo-copyright:admin/appearance/settings/openaid2'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/appearance/settings/openaid2',
    'router_path' => 'admin/appearance/settings/openaid2',
    'link_title' => 'Edit Site Appearance (colors, logo, copyright)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_edit-site-appearance-colors-logo-copyright:admin/appearance/settings/openaid2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_manage-comments:admin/content/comment
  $menu_links['menu-dashboard-links_manage-comments:admin/content/comment'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/content/comment',
    'router_path' => 'admin/content',
    'link_title' => 'Manage Comments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_manage-comments:admin/content/comment',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_manage-openaid-features:admin/modules/openaid
  $menu_links['menu-dashboard-links_manage-openaid-features:admin/modules/openaid'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/modules/openaid',
    'router_path' => 'admin/modules',
    'link_title' => 'Manage OpenAid Features',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_manage-openaid-features:admin/modules/openaid',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-dashboard-links_manage-users:admin/people
  $menu_links['menu-dashboard-links_manage-users:admin/people'] = array(
    'menu_name' => 'menu-dashboard-links',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Manage Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-dashboard-links_manage-users:admin/people',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Add Media (images, audio, video)');
  t('Additional OpenAid Settings');
  t('Edit Content');
  t('Edit Site Appearance (colors, logo, copyright)');
  t('Manage Comments');
  t('Manage OpenAid Features');
  t('Manage Users');


  return $menu_links;
}
