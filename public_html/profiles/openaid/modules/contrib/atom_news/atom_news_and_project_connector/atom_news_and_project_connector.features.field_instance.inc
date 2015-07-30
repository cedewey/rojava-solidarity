<?php
/**
 * @file
 * atom_news_and_project_connector.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function atom_news_and_project_connector_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-news-field_news_related_projects'
  $field_instances['node-news-field_news_related_projects'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul>
<li>Start typing to select related projects or organizations.</li>
<li>Authors with permission may <a href ="/node/add/project">create new projects</a>.</li>
</ul>
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_related_projects',
    'label' => 'Related Project / Organization',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 1,
        'references_dialog_edit' => 1,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<ul>
<li>Start typing to select related projects or organizations.</li>
<li>Authors with permission may <a href ="/node/add/project">create new projects</a>.</li>
</ul>
');
  t('Related Project / Organization');

  return $field_instances;
}
