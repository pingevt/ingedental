<?php
/**
 * @file
 * ingedental_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ingedental_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ingedental_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_facebook_publication_type().
 */
function ingedental_blog_default_facebook_publication_type() {
  $items = array();
  $items['link'] = entity_import('facebook_publication_type', '{
    "type" : "link",
    "label" : "Link",
    "weight" : "0",
    "description" : "You can post a link on a Page by issuing an HTTP POST request to PAGE_ID\\/feed with the publish_stream and manage_pages permissions and the following parameters.",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['photo'] = entity_import('facebook_publication_type', '{
    "type" : "photo",
    "label" : "Photo",
    "weight" : "0",
    "description" : "You can post photos to a Page\\u0027s Wall by issuing an HTTP POST request to PAGE_ID\\/photos with the publish_stream and manage_pages permissions and the following parameters.",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['post'] = entity_import('facebook_publication_type', '{
    "type" : "post",
    "label" : "Post",
    "weight" : "0",
    "description" : "You can create a post on a Page by issuing an HTTP POST request to PAGE_ID\\/feed with the publish_stream and manage_pages permissions and the following parameters. Additionally, Page posts can also be scheduled to go live at a future time up to 6 months or can be created in an \\u0022unpublished\\u0022 state where they are not visible on the pages timeline or in the page fan\\u0027s news feeds. Unpublished posts can be used as Sponsored Stories.",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ingedental_blog_node_info() {
  $items = array(
    'blog_entry' => array(
      'name' => t('Blog entry'),
      'base' => 'node_content',
      'description' => t('Dental Blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
