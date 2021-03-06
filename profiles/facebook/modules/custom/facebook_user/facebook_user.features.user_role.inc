<?php
/**
 * @file
 * facebook_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function facebook_user_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 3,
  );

  return $roles;
}
