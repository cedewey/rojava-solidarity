<?php
/**
 * @file
 * atom_hero_map_image_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_hero_map_image_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hero_map_image_front';
  $context->description = 'Add the map image hero block to the front page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'atom_hero_map_image-atom_hero_map_image' => array(
          'module' => 'atom_hero_map_image',
          'delta' => 'atom_hero_map_image',
          'region' => 'highlighted',
          'weight' => '-11',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add the map image hero block to the front page');
  t('page');
  $export['hero_map_image_front'] = $context;

  return $export;
}
