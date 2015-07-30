<?php
/**
 * @file
 * atom_blog_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_blog_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_blog_navigation';
  $context->description = 'Keeps the blog link active when viewing a blog post.';
  $context->tag = 'navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_post' => 'blog_post',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:blog',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Keeps the blog link active when viewing a blog post.');
  t('navigation');
  $export['atom_blog_navigation'] = $context;

  return $export;
}
