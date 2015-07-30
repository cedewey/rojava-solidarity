<?php
/**
 * @file
 * atom_call_to_action_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_call_to_action_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_call_to_action';
  $context->description = 'Defines where the call to action blocks appear.';
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
        'atom_call_to_action-atom_call_to_action' => array(
          'module' => 'atom_call_to_action',
          'delta' => 'atom_call_to_action',
          'region' => 'sidebar',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Defines where the call to action blocks appear.');
  t('global');
  $export['atom_call_to_action'] = $context;

  return $export;
}
