<?php
/**
 * @file
 * atom_person_articles_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_person_articles_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_person_articles';
  $context->description = 'Adds a list of articles to a person\'s profile that they have authored.';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'person' => 'person',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-atom_person_articles-block' => array(
          'module' => 'views',
          'delta' => 'atom_person_articles-block',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds a list of articles to a person\'s profile that they have authored.');
  t('type');
  $export['atom_person_articles'] = $context;

  return $export;
}
