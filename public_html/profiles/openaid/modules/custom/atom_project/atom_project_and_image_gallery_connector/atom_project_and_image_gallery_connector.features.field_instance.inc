<?php
/**
 * @file
 * atom_project_and_image_gallery_connector.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function atom_project_and_image_gallery_connector_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-project-field_project_image_gallery'
  $field_instances['node-project-field_project_image_gallery'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul>
<li>Start typing to select existing image galleries.</li>
<li>You may also create new image galleries.</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 10,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_image_gallery',
    'label' => 'Image Gallery',
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<ul>
<li>Start typing to select existing image galleries.</li>
<li>You may also create new image galleries.</li>
</ul>');
  t('Image Gallery');

  return $field_instances;
}
