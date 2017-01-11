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

function sp_mollie_email_settings_form($form, &$form_state) {
  $site_mail = variable_get('site_mail', ini_get('sendmail_from'));

  $form['intro'] = array(
  );

  $form['sp_mollie_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => 'Onderwerp',
    '#default_value' => variable_get('sp_mollie_email_subject',  ''),
    '#description' => 'De volgende variabelen zijn bruikbaar: [name], [email], [phone], [amount], [payment_id], [donation_id].',
  );

  $form['sp_mollie_email_from'] = array(
    '#type' => 'textfield',
    '#title' => 'Afzender',
    '#default_value' => variable_get('sp_mollie_email_from', $site_mail),
  );

  $default = variable_get('sp_mollie_email_body',  array());
  $form['sp_mollie_email_body'] = array(
    '#type' => 'text_format',
    '#title' => 'Inhoud',
    '#description' => 'De volgende variabelen zijn bruikbaar: [name], [email], [phone], [amount], [payment_id], [donation_id].',
    '#format' => isset($default['format']) ? $default['format'] : NULL,
    '#default_value' => isset($default['value']) ? $default['value'] : '',
  );

  $form['sp_mollie_test_email'] = array(
    '#type' => 'fieldset',
    '#title' => 'Verstuur een test email.',
  );

  $form['sp_mollie_test_email']['sp_mollie_email_test'] = array(
    '#type' => 'textfield',
    '#title' => 'Test e-mailadres',
    '#prefix' => '<div id="sp_mollie_send_test_email">',
    '#suffix' => '</div>',
    '#default_value' => variable_get('sp_mollie_email_test', $site_mail),
  );

  $form['sp_mollie_test_email']['send_email_test'] = array(
    '#type' => 'button',
    '#value' => 'Verzend',
    '#name' => 'send_test_email',
    '#ajax' => array(
      'wrapper' => 'sp_mollie_send_test_email',
      'callback' => 'sp_mollie_send_test_email',
    ),
  );

  return system_settings_form($form);
}

function sp_mollie_send_test_email($form, &$form_state) {
  $values = $form_state['values'];
  $message = drupal_mail('sp_mollie', 'test_email', $values['sp_mollie_email_test'], language_default(), $values, $values['sp_mollie_email_from']);
  if (!empty($message['result'])) {
    // Mail verzonden.
    drupal_set_message('Er is een test e-mail verzonden.');
  }
  else {
    // Mail faal.
    drupal_set_message('Er is iets misgegaan met het verzenden van de e-mail.', 'error');
  }

  $form['sp_mollie_email_test']['sp_mollie_email_test']['#prefix'] = theme_status_messages();
  return $form['sp_mollie_email_test']['sp_mollie_email_test'];
}

