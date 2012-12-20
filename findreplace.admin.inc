<?php
// $Id$

/**
 * @file
 * Admin page callback for the findreplace module.
 */

/**
 * Builds and returns the findreplace settings form.
 */
function findreplace_admin_settings() {
  
  $form = array();
  $form['findreplace_max'] = array(
    '#type' => 'select',
    '#title' => t('Maximum number of replacements per run'),
    '#options' => drupal_map_assoc(range(1, 100)),
    '#default_value' => variable_get('findreplace_max', 100),
    '#description' => t('Just trying to avoid doing massive database updates.'),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}
