<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

//  /**
//  * Implements hook_form_user_login_block_alter().
//  */
// function facebook_form_user_login_block_alter(&$form, &$form_state, $form_id) {
//   $form['name']['#size'] = 15;
//   $form['name']['#title'] = t('Email');
//   $form['pass']['#size'] = 15;
//   $markup = l(t('Forgotten account?'), 'user/password');
//   // $markup = '<div>' . $markup . '</div>';
//   $markup = '<div class="clearfix-login">' . $markup . '</div>';
//   $form['links']['#markup'] = $markup;
//   $form['links']['#weight'] = 100;
// }

// /**
// * Implements hook_form_form_id_alter().
// */
// function facebook_form_alter(&$form, &$form_state, $form_id){
//  if ($form_id == 'user_register_form') {
//   //  dsm($form);
//    $form['customtext_1'] = array(
//      '#type' => 'item',
//      '#markup' => '<div ><label>It&apos;s free and always will be.</label></div>',
//      '#weight' => -1, // Adjust so that you can place it whereever
//      );
//
//      $form['password'] = array(
//        '#type' => 'password',
//        '#title' => t('Password'),
//        '#description' => t('Please enter your password'),
//        '#attributes' => array('placeholder' => t('New password')),
//        '#size' => 30,
//        '#maxlength' => 30,
//        '#required' => TRUE,
//        '#weight' => 10,
//       );
//
//       $form['customtext_2'] =array(
//         '#type' =>'item',
//         '#markup' => '<div><a href="#">Why do I need to provide my date of birth?</a></div>',
//         '#weight' => 10,
//       );
//
//       $form['customtext_3'] =array(
//         '#type' =>'item',
//         '#markup' => '<div>By clicking Create an account, you agree to our <a href="#">Terms</a> and<span class="span-display">confirm that you have read our <a href="#">Data Policy</a>, including our <a href="#">Cookie</a></span><a href="#">Use Policy</a>.You may receive SMS message notifications from<span class="span-display"> Facebook and can opt out at any time.</span>',
//         '#weight' => 10,
//       );
//
//       $form['customtext_4'] =array(
//         '#type' =>'item',
//         '#markup' => '<div><p class="content" id="content1"><a href="#">Create a Page</a> for a celebrity, band or business.</p></div>',
//         '#weight' => 35,
//       );
//       //  $form['field_first_name']['#title_display'] = 'invisible';
//       $form['field_account_gender'][LANGUAGE_NONE]['#title_display'] = 'invisible';
//     }
//
// }
