<?php
/**
 * @file
 * atom_partners_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_partners_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_partner_navigation';
  $context->description = 'Keeps the partners link active when viewing partners.';
  $context->tag = 'navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'partner' => 'partner',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:partners',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Keeps the partners link active when viewing partners.');
  t('navigation');
  $export['atom_partner_navigation'] = $context;

  return $export;
}
