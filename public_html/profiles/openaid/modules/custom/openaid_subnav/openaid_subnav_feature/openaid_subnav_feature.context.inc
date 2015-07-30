<?php
/**
 * @file
 * openaid_subnav_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_subnav_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sub_nav';
  $context->description = 'Sub-Navigation Menu Block';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-openaid_subnav-1' => array(
          'module' => 'menu_block',
          'delta' => 'openaid_subnav-1',
          'region' => 'subnav',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub-Navigation Menu Block');
  t('global');
  $export['sub_nav'] = $context;

  return $export;
}
