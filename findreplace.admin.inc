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
  $form['findreplace_search_style'] = array(
    '#type' => 'select',
    '#title' => t('Type of database search performed'),
    '#options' => drupal_map_assoc(array('default','fulltext')),
    '#default_value' => variable_get('findreplace_search_style', 'default'),
    '#description' => t('Default search can use Drupal core tables, but is slow. Fulltext search requires a separate table (see documentation), but is much faster.'),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}
