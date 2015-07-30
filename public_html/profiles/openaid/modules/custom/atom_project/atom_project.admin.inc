<?php

/**
 * Configuration form
 */
function atom_project_admin_project_form($form, &$form_state) {
  $form['intro'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Configure the Atom Project module.') . '</p>',
  );

  $centerpoint = atom_project_map_default_centerpoint();
  $centerpoint = $centerpoint['lat'] . ', ' . $centerpoint['lon'];

  $form['map'] = array(
    '#type' => 'fieldset',
    '#title' => t('Map Settings'),
    'height' => array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#description' => t('Set the map height used for the project map, e.g. 400px'),
      '#default_value' => atom_project_map_height(),
    ),
    'zoom' => array(
      '#type' => 'textfield',
      '#title' => t('Zoom level'),
      '#default_value' => atom_project_map_default_zoom(),
      '#description' => t('Default zoom for the project map. Larger number means the map is zoomed in closer. Used only if centering on a project.'),
    ),
  );

  $attributes = array();
  if (atom_project_map_center_on_project()) {
    $attributes['checked'] = 'checked';
  }

  $form['map']['center_on_project'] = array(
    '#type' => 'checkbox',
    '#title' => t('Center on project'),
    '#description' => t('On project pages, center the project map on the project location if available'),
    '#attributes' => $attributes,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['restore_defaults'] = array(
    '#type' => 'submit',
    '#value' => t('Restore defaults'),
  );

  return $form;
}

/**
 * Configuration validation
 */
function atom_project_admin_project_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    // check the height input
    if (!preg_match('/^(\d+)\s*(px|em)$/', $form_state['values']['height'])) {
      form_set_error('height', t('Invalid height. Height should specify pixel amount, e.g. 400px'));
    }

    // check the centerpoint input
    if (!preg_match('/^([0-9,\.\- ]+)$/', $form_state['values']['centerpoint'])) {
      form_set_error('centerpoint', t('Invalid centerpoint. Should be: lat, lon'));
    }
    $centerpoint = explode(',', $form_state['values']['centerpoint']);
    if (count($centerpoint) !== 2) {
      form_set_error('centerpoint', t('Invalid centerpoint. Centerpoint needs to contain both lat and lon values.'));
    }

    // check zoom
    if (!preg_match('/^([0-9])$/', $form_state['values']['zoom'])) {
      form_set_error('zoom', t('Invalid zoom setting'));
    }
  }
}

/**
 * Submit handler for the configuration screen
 */
function atom_project_admin_project_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    if (isset($form_state['values']['height'])) {
      variable_set('atom_project_map_height', check_plain($form_state['values']['height']));
    }
    if (isset($form_state['values']['centerpoint'])) {
      $data = explode(',', $form_state['values']['centerpoint']);
      $centerpoint = array('lat' => trim($data[0]), 'lon' => trim($data[1]));
      variable_set('atom_project_map_default_centerpoint', $centerpoint);
    }

    if (isset($form_state['values']['center_on_project'])) {
      $value = FALSE;
      if (intval($form_state['values']['center_on_project'])) {
        $value = TRUE;
      }
      variable_set('atom_project_map_center_on_project', $value);
    }

    if (isset($form_state['values']['zoom'])) {
      variable_set('atom_project_map_default_zoom', intval($form_state['values']['zoom']));
    }

    drupal_set_message(t('Settings saved'));
    return;
  }

  variable_del('atom_project_map_height');
  variable_del('atom_project_map_default_centerpoint');
  variable_del('atom_project_map_center_on_project');
  drupal_set_message(t('Defaults restored'));
}

/**
 * Global map settings
 */
function atom_project_admin_global_map_form($form, &$form_state) {
  $form['tileset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tileset'),
    'template' => array(
      '#type' => 'textfield',
      '#title' => t('URL template'),
      '#default_value' => atom_project_map_earth_tileset(),
      '#description' => t('Tileset template for the earth tileset, e.g. http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png'),
    ),
    'attribution' => array(
      '#type' => 'textfield',
      '#title' => t('Attribution'),
      '#default_value' => atom_project_map_earth_tileset_attribution(),
    ),
  );

  $marker = atom_project_map_marker();
  $form['markers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Markers'),
    'marker' => array(
      '#type' => 'managed_file',
      '#title' => 'Marker image (standard)',
      '#default_value' => $marker['marker_standard_file'],
      '#description' => 'Provide a marker image.',
      '#weight' => 10,
    ),
    'marker_retina' => array(
      '#type' => 'managed_file',
      '#title' => 'Marker image (retina)',
      '#default_value' => $marker['marker_retina_file'],
      '#description' => 'Provide a retina marker image.',
      '#weight' => 10,
    ),
    'icon_anchor' => array(
      '#type' => 'textfield',
      '#title' => t('Icon Anchor Coordinates'),
      '#description' => t('Coordinates on the marker image that points to a coordinate, e.g. -3, 10'),
      '#default_value' => $marker['icon_anchor'],
      '#weight' => 20,
    ),
    'shadow' => array(
      '#type' => 'managed_file',
      '#title' => 'Shadow image (standard)',
      '#default_value' => $marker['shadow_standard_file'],
      '#description' => 'Provide a shadow image.',
      '#weight' => 30,
    ),
    'shadow_retina' => array(
      '#type' => 'managed_file',
      '#title' => 'Shadow image (retina)',
      '#default_value' => $marker['shadow_retina_file'],
      '#description' => 'Provide a retina shadow image.',
      '#weight' => 40,
    ),
    'shadow_anchor' => array(
      '#type' => 'textfield',
      '#title' => t('Shadow Anchor Coordinates'),
      '#description' => t('Coordinates on the shadow image that points to a coordinate, e.g. -3, 10'),
      '#default_value' => $marker['shadow_anchor'],
      '#weight' => 50,
    ),
    'popup_anchor' => array(
      '#type' => 'textfield',
      '#title' => t('Popup Anchor Coordinates'),
      '#description' => t('Coordinates for the popup anchor for the marker image, e.g. -3, 10'),
      '#default_value' => $marker['popup_anchor'],
      '#weight' => 60,
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['restore_defaults'] = array(
    '#type' => 'submit',
    '#value' => t('Restore defaults'),
  );

  return $form;
}

/**
 * Validation for global map settings
 */
function atom_project_admin_global_map_form_validate($form, &$form_state) {

  // validate the url template, making sure it has the dynamic parts of the URL
  // used to grab tiles
  if (isset($form_state['values']['template'])) {
    $template = $form_state['values']['template'];
    if (strpos($template, '{s}') === FALSE || strpos($template, '{x}') === FALSE || strpos($template, '{y}') === FALSE || strpos($template, '{z}') === FALSE) {
      form_set_error('template', 'Invalid tileset URL template');
    }
  }

  // validate the anchor fields
  $anchors = array('icon_anchor', 'shadow_anchor', 'popup_anchor');
  foreach ($anchors as $anchor) {
    if (isset($form_state['values'][$anchor])) {
      $value = trim($form_state['values'][$anchor]);
      if ($value) {
        $anchor_coordinates = explode(',', $value);
        array_walk($anchor_coordinates, 'trim');
        if (count($anchor_coordinates) === 2) {
          if (preg_match('/^([0-9\- ])+$/', $anchor_coordinates[0]) && preg_match('/^([0-9\- ])+$/', $anchor_coordinates[1])) {
            continue;
          }
        }
        form_set_error($anchor, t('Invalid anchor value for %anchor', array('%anchor' => $anchor)));
      }
    }
  }
  $files = array('marker', 'marker_retina', 'shadow', 'shadow_retina');
  foreach ($files as $file) {
    $upload = file_save_upload($file, array(
      'file_validate_is_image' => array(),
      'file_validate_extensions' => array('png gif jpg jpeg'),
    ));
    if ($upload) {
      if ($upload = file_move($upload, 'public://')) {
        $form_state['storage'][$file] = $upload;
        continue;
      }

      form_set_error($file, t('Could not save image %image to the upload directory', array('%image' => $file)));
    }
  }
}

/**
 * Submit handler for the global map settings
 */
function atom_project_admin_global_map_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    // capture these things into Drupal variables
    $capture = array(
      'template' => 'atom_project_earth_tileset',
      'attribution' => 'atom_project_earth_tileset_attribution',
      'icon_anchor' => 'atom_project_marker_icon_anchor',
      'shadow_anchor' => 'atom_project_marker_shadow_anchor',
      'popup_anchor' => 'atom_project_marker_popup_anchor',
    );
    foreach ($capture as $input => $setting) {
      if (isset($form_state['values'][$input])) {
        variable_set($setting, $form_state['values'][$input]);
      }
    }

    $files = array('marker', 'marker_retina', 'shadow', 'shadow_retina');
    foreach ($files as $file) {
      // figure out the variable names for this setting
      $setting = 'atom_project_' . $file . '_url';
      $full_setting = 'atom_project_' . $file . '_file';

      // if the file is being uploaded, handle that
      if (isset($form_state['storage'][$file])) {
        // change the file to permanent
        $file = $form_state['storage'][$file];
        unset($form_state['storage'][$file]);
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);

        // track that this module is using this
        file_usage_add($file, 'atom_project', 'map', 1);

        // save the url & fid
        variable_set($setting, file_create_url($file->uri));
        variable_set($full_setting, $file->fid);
      }
      // check if the user has removed this image
      elseif ($form_state['values'][$file] === 0) {
        $current = variable_get($full_setting, '');
        if ($current) {
          $current_file = file_load($current);
          file_usage_delete($current_file, 'atom_project');
          file_delete($current_file);
        }
      }
    }

    drupal_set_message(t('Settings saved'));
    return;
  }

  $settings = array_values($capture);
  foreach ($settings as $setting) {
    variable_del($setting);
  }
  variable_del('atom_project_marker_url');
  variable_del('atom_project_marker_retina_url');
  variable_del('atom_project_marker_shadow_url');
  variable_del('atom_project_marker_shadow_retina_url');
  variable_del('atom_project_marker_file');
  variable_del('atom_project_marker_retina_file');
  variable_del('atom_project_marker_shadow_file');
  variable_del('atom_project_marker_shadow_retina_file');

  drupal_set_message(t('Defaults restored'));
}

/**
 * Configuration form
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function atom_project_map_block_admin_project_form($form, &$form_state) {
  $form['intro'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Configure the Atom Project Map block for the !projects.', array('!projects' => l(t('Projects page'), 'projects'))) . '</p>',
  );

  $centerpoint = atom_project_map_block_default_centerpoint();

  $form['map'] = array(
    '#type' => 'fieldset',
    '#title' => t('Map Settings'),
    'height' => array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#description' => t('Set the map height used for the project map block, e.g. 400px'),
      '#default_value' => atom_project_map_block_height(),
    ),
  );
  $form['defaults'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default location'),
    '#description' => t('The centerpoint and zoom defaults are used when there are no projects to display. Leaflet requires a centerpoint and zoom value to work properly.'),
    'centerpoint' => array(
      '#type' => 'container',
      'lat' => array(
        '#type' => 'textfield',
        '#title' => t('Centerpoint Lat'),
        '#default_value' => $centerpoint['lat'],
      ),
      'lon' => array(
        '#type' => 'textfield',
        '#title' => t('Centerpoint Lon'),
        '#default_value' => $centerpoint['lon'],
      ),
    ),
    'zoom' => array(
      '#type' => 'textfield',
      '#title' => t('Zoom'),
      '#default_value' => atom_project_map_block_default_zoom(),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['restore_defaults'] = array(
    '#type' => 'submit',
    '#value' => t('Restore defaults'),
  );

  return $form;
}

/**
 * Configuration validation
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function atom_project_map_block_admin_project_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    // check the height input
    if (!preg_match('/^(\d+)\s*(px|em)$/', $form_state['values']['height'])) {
      form_set_error('height', t('Invalid height. Height should specify pixel amount, e.g. 400px'));
    }

    // check the zoom value
    if (!preg_match('/^\d+$/', $form_state['values']['zoom'])) {
      form_set_error('zoom', t('Invalid zoom level. Zoom should be a number.'));
    }

    // check the latitude value
    if (!preg_match('/^-?[0-9\.]+$/', $form_state['values']['lat'])) {
      form_set_error('lat', t('Invalid latitude. Latitude should be numeric.'));
    }

    // check the longitude value
    if (!preg_match('/^-?[0-9\.]+$/', $form_state['values']['lon'])) {
      form_set_error('lon', t('Invalid longitude. Longitude should be numeric.'));
    }
  }
}

/**
 * Submit handler for the configuration screen
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function atom_project_map_block_admin_project_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    if (isset($form_state['values']['height'])) {
      variable_set('atom_project_map_block_height', check_plain($form_state['values']['height']));
    }

    if (isset($form_state['values']['zoom'])) {
      variable_set('atom_project_map_block_default_zoom', intval($form_state['values']['zoom']));
    }

    // save the lat/lon values
    $lat = $lon = NULL;
    if (isset($form_state['values']['lat'])) {
      $lat = floatval($form_state['values']['lat']);
    }
    if (isset($form_state['values']['lon'])) {
      $lon = floatval($form_state['values']['lon']);
    }
    if ($lat && $lon) {
      variable_set('atom_project_map_block_default_centerpoint', array('lat' => $lat, 'lon' => $lon));
    }

    drupal_set_message(t('Settings saved'));
    return;
  }

  variable_del('atom_project_map_block_default_centerpoint');
  variable_del('atom_project_map_block_default_zoom');
  variable_del('atom_project_map_block_height');
  drupal_set_message(t('Defaults restored'));
}
