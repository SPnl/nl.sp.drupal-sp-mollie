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
function sp_mollie_api_settings_form($form, &$form_state) {
  // API key field.
  $form['sp_mollie_api_key'] = array(
    '#type' => 'textfield',
    '#title' => 'Mollie API key',
    '#required' => TRUE,
    '#default_value' => variable_get('sp_mollie_api_key',  'test_61lRKc1ZV8CHecChTTrG94O5AimOz5'),
    '#size' => 50,
    '#maxlength' => 50,
  );

  return system_settings_form($form);
}

function sp_mollie_landing_page_settings_form($form, &$form_state) {
  $form['sp_mollie_feedback_is_paid'] = array(
    '#type' => 'textarea',
    '#title' => 'Status: is betaald',
    '#default_value' => variable_get('sp_mollie_feedback_is_paid',  '<p>Dank, uw donatie is ontvangen.</p>'),
  );

  $form['sp_mollie_feedback_is_open'] = array(
    '#type' => 'textarea',
    '#title' => 'Status: onafgerond',
    '#default_value' => variable_get('sp_mollie_feedback_is_open',  '<p>De betaling van uw donatie is op dit moment nog niet afgerond.</p>'),
  );

  $form['sp_mollie_feedback_is_cancelled'] = array(
    '#type' => 'textarea',
    '#title' => 'Status: geannuleerd',
    '#default_value' => variable_get('sp_mollie_feedback_is_cancelled',  '<p>Helaas, de betaling van uw donatie is geannuleerd.</p>'),
  );

  $form['sp_mollie_feedback_error'] = array(
    '#type' => 'textarea',
    '#title' => 'Status: fout',
    '#default_value' => variable_get('sp_mollie_feedback_error',  '<p>Helaas, er is een fout opgetreden.</p>'),
  );

  $form['sp_mollie_feedback_no_id'] = array(
    '#type' => 'textarea',
    '#title' => 'Status: geen betalings id gevonden',
    '#default_value' => variable_get('sp_mollie_feedback_error',  '<p>Helaas, er is iets misgegaan met het ophalen van uw donatiegegevens.</p>'),
  );

  return system_settings_form($form);
}
