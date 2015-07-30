<?php
/**
 * @file
 * Helpers for use in the theme.
 */

/**
 * Return default copyright message
 */
function openaid2_default_copyright() {
  return t('Copyright © @year', array('@year' => format_date(time(),'custom','Y')));
}
