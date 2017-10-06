<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function facebook_form_user_login_block_alter(&$form, &$form_state, $form_id) {
  $form['name']['#size'] = 15;
  $form['name']['#title'] = t('Email');
  $form['pass']['#size'] = 15;
  $markup = l(t('Forgotten account?'), 'user/password');
  $markup = '<div class="clearfix">' . $markup . '</div>';
  $form['links']['#markup'] = $markup;
  // $form['links']['#weight'] = 10000;
}
