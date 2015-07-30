<?php

/**
 * Implements hook_preprocess_node()
 */
function openaid2_preprocess_node(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $type = $vars['type'];
  $mode = $vars['view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  // Uncomment the lines below to see variables you can use to target a field.
  // This requires http://drupal.org/project/devel to be installed.
  // dpm($type, 'Type:');
  // dpm($mode, 'Mode:');

  // Example: Adding a classes base on view mode.
  // switch ($mode) {
  //   case 'photo_teaser':
  //     $classes[] = 'bg-white gutters-half l-space-trailing';
  //     break;
  // }

  // Remove Read more link from links.
  unset($vars['content']['links']['node']);

  if (isset($vars['content']['links']['comment'])) {
    // Hacky way to move comments after sharethis since theme_list does not
    // respect #weight.
    $comment = $vars['content']['links']['comment'];
    unset($vars['content']['links']['comment']);
    $vars['content']['links']['comment'] = $comment;

    // Remove new comments link.
    unset($vars['content']['links']['comment']['#links']['comment-new-comments']);

    // Add comment icons.
    foreach ($vars['content']['links']['comment']['#links'] as $link => $value) {
      if (isset($value['fragment']) && $value['fragment'] == 'comments') {
        $icon = '<i class="fa fa-comments"></i>';
      } else {
        $icon = '<i class="fa fa-comment"></i>';
      }
      $vars['content']['links']['comment']['#links'][$link]['title'] = $icon . ' ' . $value['title'];
      $vars['content']['links']['comment']['#links'][$link]['html'] = TRUE;
    }
  }

  // Add a heading to share this so we have something to toggle;
  if (isset($vars['content']['links']['sharethis']['#links']['sharethis']['title'])) {
    $heading = '<button class="sharethis-toggle">' . t('Share') . '</button>';
    $vars['content']['links']['sharethis']['#links']['sharethis']['title'] =
      $heading . $vars['content']['links']['sharethis']['#links']['sharethis']['title'];
  }
  // Declare which preprocess functions to run.
  $preprocesses = array(
    $mode,
    $type,
    $type . '__' . $mode,
  );

  center_preprocessors($vars, __FUNCTION__, $preprocesses);
}

/**
 * Extends hook_preprocess_node() for Marquee nodes.
 */
function openaid2_preprocess_node__marquee(&$vars) {
  // Get the image node.
  $node_wrapper = entity_metadata_wrapper('node', $vars['node']);
  $image = $node_wrapper->field_marquee_image->value();

  if($image) {
    $image_uri = $image['uri'];
    $vars['image_paths'] = array(
      'small' => image_style_url('atom_marquee_small', $image_uri),
      'large' => image_style_url('atom_marquee', $image_uri),
    );
  }
  $selector = '#node-' . $vars['node']->nid . '.marquee--teaser';
  drupal_add_css(
    $selector . ' {
      background-image: url(' . $vars['image_paths']['small'] . ');
    }
    @media (min-width: 700px) {
      ' . $selector . ' {
        background-image: url(' . $vars['image_paths']['large'] . ');
      }
    }
  ', array('type' => 'inline'));
}

/**
 * Extends hook_preprocess_node() for Gallery nodes.
 */
function openaid2_preprocess_node__image_gallery(&$vars) {
  // Get the image node.
  $node_wrapper = entity_metadata_wrapper('node', $vars['node']);
  $image = $node_wrapper->field_gallery_media_images->value();

  if ($image) {
    $image_uri = $image[0]['uri'];
    $vars['image_path'] = image_style_url('atom_image_gallery_teaser', $image_uri);
  } else {
    $vars['image_path'] = "";
  }
}
