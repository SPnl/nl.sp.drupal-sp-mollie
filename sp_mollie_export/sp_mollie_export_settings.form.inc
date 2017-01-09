<?php

/**
 * @file
 * Definition and theming of settings form
 */

/**
 * Creates settings form.
 *
 * @param mixed $form
 *   Drupal form object.
 *
 * @param mixed $form_state
 *   Drupal form state object.
 */
function sp_mollie_export_settings_form($form, &$form_state) {

  preg_match('/^(.+)\(([0-9]+)\)$/', variable_get('sp_mollie_export_group', ''), $matches);
  if (!empty($matches[1]) && !empty($matches[2])) {
    $default = $matches[1] . ' (' . $matches[2] . ')';
  }
  else {
    $default = '';
  }
  $form['sp_mollie_export_group'] = array(
    '#type' => 'textfield',
    '#title' => 'CiviCRM groep',
    '#description' => 'Selecteer CiviCRM groep waaraan de donateurs moeten worden toegevoegd.',
    '#prefix' => 'Ververs de cache als de groep recent is toegevoegd in CiviCRM.',
    '#autocomplete_path' => 'donatie/group/autocomplete',
    '#default_value' => $default,
  );

  return system_settings_form($form);
}
