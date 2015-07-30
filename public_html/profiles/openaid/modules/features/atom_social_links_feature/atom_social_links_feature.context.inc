<?php
/**
 * @file
 * atom_social_links_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_social_links_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_social_links';
  $context->description = 'Adds social links to the footer.';
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
        'social_links-social_links' => array(
          'module' => 'social_links',
          'delta' => 'social_links',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds social links to the footer.');
  t('global');
  $export['atom_social_links'] = $context;

  return $export;
}
