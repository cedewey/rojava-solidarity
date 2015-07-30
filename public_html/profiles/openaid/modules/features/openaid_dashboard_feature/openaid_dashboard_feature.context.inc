<?php
/**
 * @file
 * openaid_dashboard_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openaid_dashboard_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openaid_dashboard';
  $context->description = 'Add links to the user dashboard.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-dashboard-links' => array(
          'module' => 'menu',
          'delta' => 'menu-dashboard-links',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'comment-recent' => array(
          'module' => 'comment',
          'delta' => 'recent',
          'region' => 'dashboard_sidebar',
          'weight' => '-9',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'dashboard_sidebar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add links to the user dashboard.');
  t('page');
  $export['openaid_dashboard'] = $context;

  return $export;
}
