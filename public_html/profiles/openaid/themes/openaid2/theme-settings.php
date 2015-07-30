<?php

include 'inc/helpers.inc';

/**
 * Add theme settings for the Openaid2 theme
 *
 * Settings: Main Logo, Primary Color, Secondary Color, Copyright, Footer Logo
 */
function openaid2_form_system_theme_settings_alter(&$form, &$form_state) {

  $settings = array(
    'primary_color' => 'cc0000',
    'secondary_color' => '006699',
    'copyright' => openaid2_default_copyright(),
    'footer_logo' => '',
    'default_footer_logo' => '',
    'footer_logo_path' => '',
    'footer_logo_upload' => '',
  );
  foreach (array_keys($settings) as $key) {
    $theme_setting = theme_get_setting($key);
    if ($theme_setting !== NULL) {
      $settings[$key] = $theme_setting;
    }
  }

  $form['color_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color settings'),
    '#description' => t('Select colors for the Openaid2 theme.'),
  );
  $form['color_settings']['primary_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Primary Color'),
    '#default_value' => $settings['primary_color'],
  );
  $form['color_settings']['secondary_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Secondary Color'),
    '#default_value' => $settings['secondary_color'],
  );

  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer'),
    '#description' => t('Settings for the Openaid2 footer'),
  );
  $form['footer']['copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Copyright text'),
    '#default_value' => $settings['copyright'],
  );

  // copy the image logo settings and change em up
  $form['footer_logo'] = $form['logo'];
  $form['footer_logo']['#title'] = t('Footer Logo Image Settings');
  $form['footer_logo']['default_footer_logo'] = $form['footer_logo']['default_logo'];
  $form['footer_logo']['default_footer_logo']['#default_value'] = $settings['default_footer_logo'];
  $form['footer_logo']['settings']['#states']['invisible'] = array('input[name="default_footer_logo"]' => array('checked' => TRUE));
  $form['footer_logo']['settings']['footer_logo_path'] = $form['footer_logo']['settings']['logo_path'];
  $form['footer_logo']['settings']['footer_logo_path']['#default_value'] = $settings['footer_logo_path'];
  $form['footer_logo']['settings']['footer_logo_upload'] = $form['footer_logo']['settings']['logo_upload'];
  // $form['footer_logo']['settings']['footer_logo_upload']['#type'] = 'managed_file';
  $form['footer_logo']['settings']['footer_logo_upload']['#default_value'] = $settings['footer_logo_upload'];
  unset(
    $form['footer_logo']['default_logo'],
    $form['footer_logo']['settings']['logo_path'],
    $form['footer_logo']['settings']['logo_upload']
  );

  // move settings down in the footer_logo array
  $settings = $form['footer_logo']['settings'];
  unset($form['footer_logo']['settings']);
  $form['footer_logo']['settings'] = $settings;

  // add our validation handler to deal with the new theme settings
  if (!isset($form['#validate'])) {
    $form['#validate'] = array();
  }
  array_push($form['#validate'], 'openaid2_theme_settings_validate');

  if (!isset($form['#submit'])) {
    $form['#submit'] = array();
  }
  array_push($form['#submit'], 'openaid2_theme_settings_submit');
}

/**
 * Validate theme settings
 */
function openaid2_theme_settings_validate($form, &$form_state) {
  $file = 'footer_logo_upload';
  $upload = file_save_upload($file, array(
    'file_validate_is_image' => array(),
    'file_validate_extensions' => array('png gif jpg jpeg'),
  ));
  if ($upload) {
    if ($upload = file_move($upload, 'public://')) {
      $form_state['storage'][$file] = $upload;
      return;
    }

    form_set_error($file, t('Could not save image %image to the upload directory', array('%image' => $file)));
  }
}

/**
 * Submit handler for additional settings
 */
function openaid2_theme_settings_submit($form, &$form_state) {
  $file = 'footer_logo_upload';

  // if the file is being uploaded, handle that
  if (isset($form_state['storage'][$file])) {
    // change the file to permanent
    $file = $form_state['storage'][$file];
    unset($form_state['storage'][$file]);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);

    // track that this module is using this
    file_usage_add($file, 'openaid2', 'theme', 1);

    // save the url & fid
    $form_state['values']['footer_logo_path'] = file_create_url($file->uri);
  }

}
