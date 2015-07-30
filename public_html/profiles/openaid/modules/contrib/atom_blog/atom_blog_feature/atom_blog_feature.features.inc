<?php
/**
 * @file
 * atom_blog_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atom_blog_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function atom_blog_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function atom_blog_feature_image_default_styles() {
  $styles = array();

  // Exported image style: atom_blog_full.
  $styles['atom_blog_full'] = array(
    'label' => 'atom_blog_full',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: atom_blog_teaser.
  $styles['atom_blog_teaser'] = array(
    'label' => 'atom_blog_teaser',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
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
function atom_blog_feature_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Use for creating new blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
