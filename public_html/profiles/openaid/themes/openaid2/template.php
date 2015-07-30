<?php
/**
 * @file
 * Template stuff.
 */

include 'inc/helpers.inc';

include 'inc/block.inc';
include 'inc/field.inc';
include 'inc/form.inc';
include 'inc/menu.inc';
include 'inc/node.inc';
include 'inc/page.inc';

/**
 * Return the theme setting or default
 */
function openaid2_get_setting($setting, $default = NULL) {
  $theme_setting = theme_get_setting($setting);
  if ($theme_setting !== NULL) {
    return $theme_setting;
  }
  return $default;
}
