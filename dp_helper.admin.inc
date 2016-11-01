<?php

/**
 * Implements hook_settings().
 */
function dp_helper_settings($form_state) {

  /*$form['dp_helper_budget'] = array(
    '#type' => 'textfield',
    '#title' => t('The budget for the month'),
    '#description' => t('The budget for the month (dp_helper_budget)'),
    '#default_value' => variable_get('dp_helper_budget', 1000),
    '#size' => 10,
    '#maxlength' => 4,
  );*/

  $form['dp_helper_reward_google'] = array(
    '#type' => 'textfield',
    '#title' => t('Google reward'),
    '#description' => t('Google reward, EUR (dp_helper_reward_google)'),
    '#default_value' => variable_get('dp_helper_reward_google', 2.5),
    '#size' => 10,
    '#maxlength' => 7,
  );

  $form['dp_helper_reward_yandex'] = array(
    '#type' => 'textfield',
    '#title' => t('Yandex reward'),
    '#description' => t('Yandex reward, RUB (dp_helper_reward_yandex)'),
    '#default_value' => variable_get('dp_helper_reward_yandex', 100),
    '#size' => 10,
    '#maxlength' => 7,
  );

  $form['dp_helper_reward_links_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Links 1 reward'),
    '#description' => t('Links 1 reward, RUB (dp_helper_reward_links_1)'),
    '#default_value' => variable_get('dp_helper_reward_links_1', 3000),
    '#size' => 10,
    '#maxlength' => 5,
  );

  /*$form['dp_helper_er_eur'] = array(
    '#type' => 'textfield',
    '#title' => t('EUR exchange rate'),
    '#description' => t('EUR exchange rate (dp_helper_er_eur)'),
    '#default_value' => variable_get('dp_helper_er_eur', 25),
    '#size' => 10,
    '#maxlength' => 4,
  );*/

  /*$form['dp_helper_er_usd'] = array(
    '#type' => 'textfield',
    '#title' => t('USD exchange rate'),
    '#description' => t('USD exchange rate (dp_helper_er_usd)'),
    '#default_value' => variable_get('dp_helper_er_usd', 21),
    '#size' => 10,
    '#maxlength' => 4,
  );*/

  /*$form['dp_helper_er_rub'] = array(
    '#type' => 'textfield',
    '#title' => t('RUB exchange rate'),
    '#description' => t('RUB exchange rate (dp_helper_er_rub)'),
    '#default_value' => variable_get('dp_helper_er_rub', 31),
    '#size' => 10,
    '#maxlength' => 4,
  );*/

  $form['dp_helper_date_start'] = array(
    '#type' => 'textfield',
    '#title' => t('Start date'),
    '#description' => t('Start date (dp_helper_date_start). Default: "first day of this month 00:00:00"'),
    '#default_value' => variable_get('dp_helper_date_start', 'first day of this month 00:00:00'),
    '#size' => 40,
    '#maxlength' => 50,
  );

  $form['dp_helper_date_end'] = array(
    '#type' => 'textfield',
    '#title' => t('End date'),
    '#description' => t('Start date (dp_helper_date_end). Default: "first day of next month 00:00:00"'),
    '#default_value' => variable_get('dp_helper_date_end', 'first day of next month 00:00:00'),
    '#size' => 40,
    '#maxlength' => 50,
  );

  $form['colorbox_rare_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rare settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['colorbox_rare_settings']['dp_helper_last_update'] = array(
    '#type' => 'textfield',
    '#title' => t('Last update'),
    '#description' => 'Last update (dp_helper_last_update). Current is: ' . date("Y.m.d H:i:s", variable_get('dp_helper_last_update', time())),
    '#default_value' => variable_get('dp_helper_last_update', time()),
    '#size' => 40,
    '#maxlength' => 50,
    '#disabled' => TRUE,
    //'#value' => date(DATE_RSS),
  );

  /*$form['colorbox_rare_settings']['dp_helper_adsense'] = array(
    '#type' => 'textfield',
    '#title' => t('Last update'),
    '#description' => 'Last update (dp_helper_adsense)',
    '#default_value' => _dp_helper_test(),
    '#size' => 40,
    '#maxlength' => 50,
    '#disabled' => TRUE,
    //'#value' => date(DATE_RSS),
  );*/

  $form['colorbox_rare_settings']['dp_helper_coeff_1'] = array(
    '#type' => 'textfield',
    '#title' => t('First coefficient'),
    '#description' => t('First coefficient (dp_helper_coeff_1)'),
    '#default_value' => variable_get('dp_helper_coeff_1', 0.5),
    '#size' => 10,
    '#maxlength' => 4,
  );

  $form['colorbox_rare_settings']['dp_helper_coeff_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Second coefficient'),
    '#description' => t('Second coefficient (dp_helper_coeff_2)'),
    '#default_value' => variable_get('dp_helper_coeff_2', 0.5),
    '#size' => 10,
    '#maxlength' => 4,
  );

  $form['#submit'][] = 'dp_helper_settings_form_submit';

  return system_settings_form($form);
}

function dp_helper_settings_form_submit($form, &$form_state) {
  //dpm($form_state['values']['dp_helper_last_update']);
  $form_state['values']['dp_helper_last_update'] = time();
}
