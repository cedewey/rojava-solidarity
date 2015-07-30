<?php
/**
 * @file
 * atom_social_links_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atom_social_links_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
