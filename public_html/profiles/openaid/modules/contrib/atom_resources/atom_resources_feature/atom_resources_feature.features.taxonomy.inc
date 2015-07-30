<?php
/**
 * @file
 * atom_resources_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function atom_resources_feature_taxonomy_default_vocabularies() {
  return array(
    'resource_types' => array(
      'name' => 'Resource Types',
      'machine_name' => 'resource_types',
      'description' => 'Use for categorizing resources.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
