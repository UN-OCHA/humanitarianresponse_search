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

  // Exported permission: 'use search_api_autocomplete for search_api_views_search'.
  $permissions['use search_api_autocomplete for search_api_views_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_search',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_saved_searches'.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_saved_searches',
  );

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  return $permissions;
}
