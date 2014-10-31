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
function sp_mollie_settings_form($form, &$form_state) {
  // API key field.
  $form['api_key'] = array(
    '#type' => 'textfield',
    '#title' => 'Mollie API key',
    '#required' => TRUE,
    '#default_value' => variable_get('sp_mollie_api_key',  'test_61lRKc1ZV8CHecChTTrG94O5AimOz5'),
    '#size' => 50,
    '#maxlength' => 50,
  );

  // Submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'submit',
  );
  return $form;
}


/**
 * Implements hook_validate().
 */
function sp_mollie_settings_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (empty($values['api_key'])) {
    form_set_error('api_key', 'Vul de Mollie API key in');
  }
}

/**
 * Implements hook_submit().
 */
function sp_mollie_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  if (!empty($values['api_key'])) {
    variable_set('sp_mollie_api_key', $values['api_key']);
    drupal_set_message('De nieuwe mollie api key is ingesteld.');
  }
}
