<?php
/**
 * @file
 * atom_marquee_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atom_marquee_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function atom_marquee_feature_image_default_styles() {
  $styles = array();

  // Exported image style: atom_marquee.
  $styles['atom_marquee'] = array(
    'name' => 'atom_marquee',
    'label' => 'atom_marquee',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 474,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: atom_marquee_small.
  $styles['atom_marquee_small'] = array(
    'name' => 'atom_marquee_small',
    'label' => 'atom_marquee_small',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 237,
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
function atom_marquee_feature_node_info() {
  $items = array(
    'marquee' => array(
      'name' => t('Marquee'),
      'base' => 'node_content',
      'description' => t('Use for featuring content on the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
