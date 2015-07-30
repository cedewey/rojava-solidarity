<?php
/**
 * @file
 * openaid_home_featured_resources_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openaid_home_featured_resources_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
