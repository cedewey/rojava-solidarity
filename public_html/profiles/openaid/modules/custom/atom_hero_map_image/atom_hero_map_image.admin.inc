<?php

/**
 * Configuration form
 */
function atom_hero_map_image_admin_project_form($form, &$form_state) {
  $form['intro'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Configure the Atom Hero Map/Image module.') . '</p>',
  );

  $centerpoint = atom_hero_map_image_project_map_default_centerpoint();

  $form['map'] = array(
    '#type' => 'fieldset',
    '#title' => t('Map Settings'),
    'height' => array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#description' => t('Set the map height used for the project map, e.g. 400px'),
      '#default_value' => atom_hero_map_image_project_map_default_height(),
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
      '#default_value' => atom_hero_map_image_project_map_default_zoom(),
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
 */
function atom_hero_map_image_admin_project_form_validate($form, &$form_state) {
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
 */
function atom_hero_map_image_admin_project_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] === $form_state['values']['submit']) {
    if (isset($form_state['values']['height'])) {
      variable_set('atom_hero_default_height', check_plain($form_state['values']['height']));
    }

    if (isset($form_state['values']['zoom'])) {
      variable_set('atom_hero_default_zoom', intval($form_state['values']['zoom']));
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
      variable_set('atom_hero_default_centerpoint', array('lat' => $lat, 'lon' => $lon));
    }

    drupal_set_message(t('Settings saved'));
    return;
  }

  variable_del('atom_hero_default_height');
  variable_del('atom_hero_default_centerpoint');
  variable_del('atom_hero_default_zoom');
  drupal_set_message(t('Defaults restored'));
}
