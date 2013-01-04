<?php
/**
 * @file
 * humanitarianresponse_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function humanitarianresponse_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function humanitarianresponse_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function humanitarianresponse_search_default_search_api_index() {
  $items = array();
  $items['node_index'] = entity_import('search_api_index', '{
    "name" : "Node index",
    "machine_name" : "node_index",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "language" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "status" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_clusters" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_contact_email" : { "type" : "text" },
        "field_contact_job_title" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_contact_lastname" : { "type" : "text" },
        "field_coordination_hubs" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_fundings" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_themes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_display_properties" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_map_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_contact_email" : { "type" : "text" },
        "field_event_contact_person" : { "type" : "text" },
        "field_link_description" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_event_date:value" : { "type" : "list\\u003Cdate\\u003E" },
        "field_document_files:field_document_files_file:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "assessment" : "assessment",
              "media_gallery" : "media_gallery",
              "humanitarian_profile" : "humanitarian_profile",
              "link" : "link",
              "page" : "page"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [  ] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [  ] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_document_type:parent" : "field_document_type:parent" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [  ] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [  ] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_contact_email" : true,
              "field_contact_job_title" : true,
              "field_contact_lastname" : true,
              "field_event_contact_email" : true,
              "field_event_contact_person" : true,
              "field_link_description" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_contact_email" : true,
              "field_contact_job_title" : true,
              "field_contact_lastname" : true,
              "field_event_contact_email" : true,
              "field_event_contact_person" : true,
              "field_link_description" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\u000D\\u000Ah2 = 3\\u000D\\u000Ah3 = 2\\u000D\\u000Astrong = 2\\u000D\\u000Ab = 2\\u000D\\u000Aem = 1.5\\u000D\\u000Au = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_contact_email" : true,
              "field_contact_job_title" : true,
              "field_contact_lastname" : true,
              "field_event_contact_email" : true,
              "field_event_contact_person" : true,
              "field_link_description" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "spaces" : "[^\\u005Cp{L}\\u005Cp{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_contact_email" : true,
              "field_contact_job_title" : true,
              "field_contact_lastname" : true,
              "field_event_contact_email" : true,
              "field_event_contact_person" : true,
              "field_link_description" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "file" : "",
            "stopwords" : "but\\u000D\\u000Adid\\u000D\\u000Athe this that those\\u000D\\u000Aetc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : [  ]
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function humanitarianresponse_search_default_search_api_server() {
  $items = array();
  $items['solr_server'] = entity_import('search_api_server', '{
    "name" : "Solr Server",
    "machine_name" : "solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "74.121.198.179",
      "port" : "8983",
      "path" : "\\u002Fsolr\\u002F",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : [  ]
  }');
  return $items;
}
