<?php
/**
 * @file
 * openaid_home_featured_partners_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_home_featured_partners_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openaid_home_featured_partners';
  $context->description = 'Adds a partner block to front page';
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
        'views-openaid_partners-partners_block' => array(
          'module' => 'views',
          'delta' => 'openaid_partners-partners_block',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds a partner block to front page');
  t('page');
  $export['openaid_home_featured_partners'] = $context;

  return $export;
}
