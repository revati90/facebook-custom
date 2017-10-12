<?php
/**
 * @file
 * facebook_sign_up_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function facebook_sign_up_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
