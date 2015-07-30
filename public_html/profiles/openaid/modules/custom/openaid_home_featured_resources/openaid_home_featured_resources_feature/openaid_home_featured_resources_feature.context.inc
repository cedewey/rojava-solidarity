<?php
/**
 * @file
 * openaid_home_featured_resources_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_home_featured_resources_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openaid_home_featured_resources';
  $context->description = 'Adds a featured resource block to the homepage';
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
        'openaid_home_featured_resources-openaid_home_featured_resources' => array(
          'module' => 'openaid_home_featured_resources',
          'delta' => 'openaid_home_featured_resources',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds a featured resource block to the homepage');
  t('page');
  $export['openaid_home_featured_resources'] = $context;

  return $export;
}
