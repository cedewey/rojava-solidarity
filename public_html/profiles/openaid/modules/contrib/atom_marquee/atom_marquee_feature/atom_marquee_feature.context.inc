<?php
/**
 * @file
 * atom_marquee_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_marquee_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_marquee_front';
  $context->description = 'Add a rotating marquee to the front page';
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
        'atom_marquee-marquee_home' => array(
          'module' => 'atom_marquee',
          'delta' => 'marquee_home',
          'region' => 'marquee',
          'weight' => '-12',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a marquee section to the front page');
  t('page');
  $export['atom_marquee_front'] = $context;

  return $export;
}
