<?php
/**
 * @file
 * Menu hooks.
 */

/**
 * Overrides theme_menu_tree().
 */
function openaid2_menu_tree__main_menu($variables) {
  return '<ul class="nav nav-stacked nav-buttons">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree().
 */
function openaid2_menu_tree__openaid_subnav_1($variables) {
  return '<ul class="nav nav-stacked">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_preprocess_menu_link().
 */
function openaid2_preprocess_menu_link(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $menu = $vars['element']['#original_link']['menu_name'];
  $mlid = $vars['element']['#original_link']['mlid'];
  $item_classes = &$vars['element']['#attributes']['class'];
  $link_classes = &$vars['element']['#localized_options']['attributes']['class'];

  // Add global classes to all menu links.
  $item_classes[] = 'nav-item';
  $link_classes[] = 'nav-link';
}
