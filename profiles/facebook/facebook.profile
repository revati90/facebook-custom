<?php
/**
 * @file
 * Enables modules and site configuration for a facebook site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function facebook_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
   $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
   $form['site_information']['site_mail']['#default_value'] = 'admin@admin.com';
   //var_dump($form);
   $form['admin_account']['account']['name']['#default_value'] = 'admin';
   $form['admin_account']['account']['mail']['#default_value'] = 'admin@admin.com';
   $form['update_notifications']['#access'] = FALSE;
}

function facebook_install_tasks(&$install_state) {
 $tasks = array();
 $tasks['facebook_default_content'] = array();
 return $tasks;
}

function facebook_default_content() {
 // print_r(" I AM COMING HERE TO CREATE USERS");
 // drupal_set_message(" I cam here too");
 $result = db_query("SELECT rid FROM {role} where name like :id",array(':id' => 'administrator'));
   $admin_rid = $result->fetchField(0);
   $roles = user_roles();
   unset($roles[1]);
   unset($roles[2]);
   unset($roles[$admin_rid]);
   foreach($roles as $key => $value) {
     $mail = 'test-' . strtolower($value) . '@osseed.com';
     $new_user = array(
       'name' => $value,
       'mail' => $mail,
       'pass' => strtolower($value),
       'status' => 1,
       'init' => $mail,
       'roles' =>array(
         $key => $value,
       ),
     );
     user_save('',$new_user);
   }
}
