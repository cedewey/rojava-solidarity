<?php
/**
 * @file
 * atom_partners_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function atom_partners_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'atom_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Atom Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All Partners';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No partners have been added.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['text'] = '[field_partner_logo]';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['path'] = '[field_partner_website]';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_partner_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partner_logo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_partner_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => 'partner_logo',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'partners_page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_partner_group',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'list-item';
  $handler->display->display_options['style_options']['class'] = 'list--ruled';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Partner Group (hidden) */
  $handler->display->display_options['fields']['field_partner_group']['id'] = 'field_partner_group';
  $handler->display->display_options['fields']['field_partner_group']['table'] = 'field_data_field_partner_group';
  $handler->display->display_options['fields']['field_partner_group']['field'] = 'field_partner_group';
  $handler->display->display_options['fields']['field_partner_group']['ui_name'] = 'Partner Group (hidden)';
  $handler->display->display_options['fields']['field_partner_group']['label'] = '';
  $handler->display->display_options['fields']['field_partner_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_group']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => 'partner_logo',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'partners';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Partners';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['atom_partners'] = $view;

  return $export;
}
