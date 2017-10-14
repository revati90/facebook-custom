<?php
/**
 * @file
 * facebook_sign_up_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function facebook_sign_up_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Modify GTranslate settings'.
  $permissions['Modify GTranslate settings'] = array(
    'name' => 'Modify GTranslate settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'gtranslate',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer form placeholder'.
  $permissions['administer form placeholder'] = array(
    'name' => 'administer form placeholder',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'form_placeholder',
  );

  // Exported permission: 'delete status messages on own profile'.
  $permissions['delete status messages on own profile'] = array(
    'name' => 'delete status messages on own profile',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statuses',
  );

  return $permissions;
}
