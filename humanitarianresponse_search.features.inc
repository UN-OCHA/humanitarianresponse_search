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
  if ($module == "ds" && $api == "ds") {
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
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function humanitarianresponse_search_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_search",
    "name" : "Search",
    "index_id" : "node_index",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "result count" : true, "fields" : [] },
    "rdf_mapping" : []
  }');
  return $items;
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
      "index_directly" : 1,
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
        "field_publication_date" : { "type" : "date" },
        "field_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_clusters" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_coordination_hubs" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_display_properties" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_emergencies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_fundings" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_themes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_contact_email" : { "type" : "string" },
        "field_event_contact_person" : { "type" : "string" },
        "field_map_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_link_description" : { "type" : "text", "boost" : "0.5" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text", "boost" : "0.5" },
        "body:summary" : { "type" : "text", "boost" : "0.5" },
        "field_organizations:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_organizations:field_organization_acronym" : { "type" : "list\\u003Ctext\\u003E" },
        "field_clusters:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_locations:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_coordination_hubs:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_emergencies:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_fundings:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_themes:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_document_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_event_date:value" : { "type" : "list\\u003Cdate\\u003E" },
        "field_map_type:name" : { "type" : "text" },
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
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_document_type:parent" : "field_document_type:parent" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
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
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
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
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
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
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
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
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "POST"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function humanitarianresponse_search_default_search_api_sort() {
  $items = array();
  $items['node_index__field_publication_date'] = entity_import('search_api_sort', '{
    "index_id" : "node_index",
    "field" : "field_publication_date",
    "name" : "Publication Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "node_index__field_publication_date",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Publication Date" },
    "rdf_mapping" : []
  }');
  $items['node_index__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "node_index",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "node_index__search_api_relevance",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  $items['node_index__type'] = entity_import('search_api_sort', '{
    "index_id" : "node_index",
    "field" : "type",
    "name" : "Content type",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "node_index__type",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Content type" },
    "rdf_mapping" : []
  }');
  return $items;
}
