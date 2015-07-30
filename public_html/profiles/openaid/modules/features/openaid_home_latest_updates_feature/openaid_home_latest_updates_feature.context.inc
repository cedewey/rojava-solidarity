<?php
/**
 * @file
 * openaid_home_latest_updates_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_home_latest_updates_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openaid_home_latest_updates';
  $context->description = 'Adds latest updates to the home page.';
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
        'views-b9446e3b30a90eeaa63a07b2cdc706d3' => array(
          'module' => 'views',
          'delta' => 'b9446e3b30a90eeaa63a07b2cdc706d3',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds latest updates to the home page.');
  t('page');
  $export['openaid_home_latest_updates'] = $context;

  return $export;
}
