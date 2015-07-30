<?php

/**
 * @file
 * Field hooks.
 */

/**
 * Implements hook_preprocess_field().
 */
function openaid2_preprocess_field(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $name = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $item_classes = array();

  // Global field styles.
  $classes = array(
    'field',
    'field--' . str_replace('_', '-', $name),
  );
  $title_classes = array('field-label');
  $content_classes = array('field-items');
  $item_classes = array('field-item');

  // Handle inline label classes.
  if (!$vars['label_hidden'] && $vars['element']['#label_display'] == 'inline') {
    $classes[] = 'field--inline-label';
  }

  // Uncomment the lines below to see variables you can use to target a field.
  // This requires http://drupal.org/project/devel to be installed.
  // dpm($name, 'Name:');
  // dpm($bundle, 'Bundle:');
  // dpm($mode, 'Mode:');

  // Example: Using an alternative theme function.
  // if($name == 'field_tags') {
  // }

  switch ($name) {
    case 'field_blog_topic':
    case 'field_blog_tags':
    case 'field_resource_type':
    case 'field_resource_topics':
    case 'field_resource_source':
    case 'field_resource_tags':
    case 'field_resource_related_projects':
    case 'field_news_tags':
    case 'field_news_topic':
      $vars['theme_hook_suggestions'][] = 'field__custom_separated';
      break;
  }

  // Apply odd or even classes along with our custom classes to each item.
  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
    $striping = $delta % 2 ? 'even' : 'odd';
    $vars['item_attributes_array'][$delta]['class'][] = $striping;
  }
}


/**
 * Overrides theme_field().
 *
 * Remove the hard coded classes so we can add them in preprocess functions.
 */
function openaid2_field($variables) {
  $output = $variables['dev_deets'];

  // If we're nuking fields, return the rendered fields with no markup.
  if (theme_get_setting('nuke_fields')) {
    foreach ($variables['items'] as $delta => $item) {
      $output .= drupal_render($item);
    }
    return $output;
  }

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div ' . $variables['title_attributes'] . '>' . $variables['label'] . '&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div ' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<div ' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}
