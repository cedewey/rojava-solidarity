<?php
/**
 * @file
 * atom_marquee_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function atom_marquee_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create marquee content'.
  $permissions['create marquee content'] = array(
    'name' => 'create marquee content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any marquee content'.
  $permissions['delete any marquee content'] = array(
    'name' => 'delete any marquee content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own marquee content'.
  $permissions['delete own marquee content'] = array(
    'name' => 'delete own marquee content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any marquee content'.
  $permissions['edit any marquee content'] = array(
    'name' => 'edit any marquee content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own marquee content'.
  $permissions['edit own marquee content'] = array(
    'name' => 'edit own marquee content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
