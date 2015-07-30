<?php

/**
 * Change the project map popup for a project location
 *
 * @param array $location_data
 *   Data of location/node data for a project
 */
function hook_atom_project_project_popup($location_data) {
  return l($location_data['title'], 'node/' . $location_data['entity_id']);
}

/**
 * Alter a project map feature.
 *
 * Features on the project maps may be points, etc. that are rendered on the
 * project map.
 */
function hook_atom_project_feature_alter(&$feature, $location, $current_project) {
}

/**
 * Alter the types used a project page's latest updates.
 *
 * By default this uses blog_post and news, if they are available, but that can
 * be changed by implementing this hook in a custom module.
 */
function hook_atom_project_update_types_alter(&$types) {
}
