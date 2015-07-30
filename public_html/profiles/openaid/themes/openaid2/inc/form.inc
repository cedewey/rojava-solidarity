<?php
/**
 * @file
 * Form hooks.
 */

/**
 * Implements hook_form_alter().
 */
function openaid2_form_alter(&$form, &$form_state, $form_id) {

  // Add placeholder text to a form.
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t("Search");
  }
}
