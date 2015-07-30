<?php
/**
 * @file
 * Page template functions.
 */

/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page(&$vars) {
  // Set default page title behavior.
  $vars['show_title'] = $vars['is_front'] ? FALSE : TRUE;
  $preprocesses = array();

  // Preprocess node pages by type.
  if (isset($vars['node'])) {
    $node_type = $vars['node']->type;
    $preprocesses[] = $node_type;
    $vars['theme_hook_suggestions'][] = 'page__' . $node_type;
  }

  // check if there is a footer logo
  $vars['footer_logo'] = '';
  $footer_settings = array(
    'default' => openaid2_get_setting('default_footer_logo', 1),
    'footer_logo_path' => openaid2_get_setting('footer_logo_path'),
  );
  $has_footer_logo = array_filter($footer_settings);

  if ($has_footer_logo) {
    $logo = FALSE;
    if ($footer_settings['default']) {
      $logo = drupal_get_path('theme', 'openaid2') . '/footer_logo.png';
    }
    elseif ($footer_settings['footer_logo_path']) {
      $logo = check_plain($footer_settings['footer_logo_path']);
    }

    if ($logo) {
      $logo = $logo;
      $logo_parsed = parse_url($logo);
      if (!isset($logo_parsed['scheme'])) {
        if (substr($logo, 0, 1) !== '/') {
          $logo = '/' . $logo;
        }
      }
      $vars['footer_logo'] = $logo;
    }
  }

  openaid2_preprocess_page_css();
  center_preprocessors($vars, __FUNCTION__, $preprocesses);
}

/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page__blog_post(&$vars) {
  $vars['show_title'] = FALSE;
}

/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page__news(&$vars) {
  $vars['show_title'] = FALSE;
}

/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page__project(&$vars) {
  $vars['show_title'] = FALSE;
}

/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page__resource(&$vars) {
  $vars['show_title'] = FALSE;
}


/**
 * Implements hook_preprocess_page().
 */
function openaid2_preprocess_page__person(&$vars) {
  $vars['show_title'] = FALSE;
}

/**
 * Output the CSS with user options
 */
function openaid2_preprocess_page_css() {
  $css = file_get_contents(drupal_get_path('theme', 'openaid2') . '/css/user-overrides.css');
  $source = array(
    'FireBrick',
    'RoyalBlue',
  );
  $replacements = array(
    '#' . openaid2_get_setting('primary_color', 'cc0000'),
    '#' . openaid2_get_setting('secondary_color', '006699'),
  );
  $css = str_replace($source, $replacements, $css);
  drupal_add_css($css, array(
    'type' => 'inline',
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'weight' => 1000,
  ));
}
