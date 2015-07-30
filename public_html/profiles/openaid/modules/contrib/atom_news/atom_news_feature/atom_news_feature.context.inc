<?php
/**
 * @file
 * atom_news_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_news_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_news_navigation';
  $context->description = 'Keeps the news link active when viewing a news article.';
  $context->tag = 'navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:news',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Keeps the news link active when viewing a news article.');
  t('navigation');
  $export['atom_news_navigation'] = $context;

  return $export;
}
