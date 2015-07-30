<?php
/**
 * @file
 * atom_call_to_action_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atom_call_to_action_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function atom_call_to_action_feature_image_default_styles() {
  $styles = array();

  // Exported image style: atom_call_to_action_teaser.
  $styles['atom_call_to_action_teaser'] = array(
    'name' => 'atom_call_to_action_teaser',
    'label' => 'atom_call_to_action_teaser',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 336,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function atom_call_to_action_feature_node_info() {
  $items = array(
    'call_to_action' => array(
      'name' => t('Call to Action'),
      'base' => 'node_content',
      'description' => t('Adds a block to the call to action display on the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
