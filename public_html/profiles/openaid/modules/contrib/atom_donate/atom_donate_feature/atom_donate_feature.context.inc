<?php
/**
 * @file
 * atom_donate_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_donate_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_donate';
  $context->description = 'Add the donate block to all pages';
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
        'atom_donate-atom_donate' => array(
          'module' => 'atom_donate',
          'delta' => 'atom_donate',
          'region' => 'utility',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add the donate block to all pages');
  t('global');
  $export['atom_donate'] = $context;

  return $export;
}
