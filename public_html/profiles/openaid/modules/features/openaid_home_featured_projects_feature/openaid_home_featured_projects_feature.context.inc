<?php
/**
 * @file
 * openaid_home_featured_projects_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_home_featured_projects_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openaid_home_featured_projects';
  $context->description = 'Adds featured projects to the homepage.';
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
        'views-04e892de800b1187f76848bb09589b37' => array(
          'module' => 'views',
          'delta' => '04e892de800b1187f76848bb09589b37',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds featured projects to the homepage.');
  t('page');
  $export['openaid_home_featured_projects'] = $context;

  return $export;
}
