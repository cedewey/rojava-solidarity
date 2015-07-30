<?php
/**
 * @file
 * atom_image_gallery_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_image_gallery_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_image_gallery_navigation';
  $context->description = 'Keeps the photos link active when viewing image galleries.';
  $context->tag = 'navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'image_gallery' => 'image_gallery',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:photos',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Keeps the photos link active when viewing image galleries.');
  t('navigation');
  $export['atom_image_gallery_navigation'] = $context;

  return $export;
}
