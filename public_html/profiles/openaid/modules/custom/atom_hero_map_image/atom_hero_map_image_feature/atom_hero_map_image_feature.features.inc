<?php
/**
 * @file
 * atom_hero_map_image_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atom_hero_map_image_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
