<?php
/**
 * @file
 * atom_partners_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function atom_partners_feature_taxonomy_default_vocabularies() {
  return array(
    'partner_group' => array(
      'name' => 'Partner Group',
      'machine_name' => 'partner_group',
      'description' => 'A way to group Partners, such as "Primary", "Secondary"',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
