<?php
/**
 * @file
 * Block hooks.
 */

/**
 * Implements hook_preprocess_block().
 */
function openaid2_preprocess_block(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $suggestions = &$vars['theme_hook_suggestions'];

  // Add global classes to all blocks.
  $title_classes[] = 'block-title';
  $content_classes[] = 'block-content';

  // Uncomment the lines below to see variables you can use to target a block.
  // This requires http://drupal.org/project/devel to be installed.
  // dpm($block_id, 'Block ID:');

  switch ($block_id) {
    case 'atom_project-atom_project_resources':
      $classes[] = "block--meta";
      break;
  }
}

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function openaid2_block_view_menu_block_openaid_base_1_alter(&$data, $block) {
  // Hide the footer menu title.
  $data['subject'] = NULL;
}
