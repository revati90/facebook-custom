<?php
/**
 * @file
 * facebook_sign_up_page.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function facebook_sign_up_page_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_gtranslate:admin/settings/gtranslate.
  $menu_links['management_gtranslate:admin/settings/gtranslate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/settings/gtranslate',
    'router_path' => 'admin/settings/gtranslate',
    'link_title' => 'GTranslate',
    'options' => array(
      'attributes' => array(
        'title' => 'GTranslate module settings control',
      ),
      'identifier' => 'management_gtranslate:admin/settings/gtranslate',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('GTranslate');

  return $menu_links;
}
