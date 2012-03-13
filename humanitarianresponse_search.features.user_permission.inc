<?php
/**
 * @file
 * humanitarianresponse_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function humanitarianresponse_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: access search_api_page
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: use custom search
  $permissions['use custom search'] = array(
    'name' => 'use custom search',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'custom_search',
  );

  return $permissions;
}
