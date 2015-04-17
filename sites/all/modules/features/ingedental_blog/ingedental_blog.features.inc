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
 * Implements hook_image_default_styles().
 */
function ingedental_blog_image_default_styles() {
  $styles = array();

  // Exported image style: blog_full_width.
  $styles['blog_full_width'] = array(
    'label' => 'Blog full width',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 580,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'blog_full_width',
        ),
        'weight' => 0,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 580,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: blog_half_width.
  $styles['blog_half_width'] = array(
    'label' => 'Blog half width',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 290,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'blog_half_width',
        ),
        'weight' => 0,
      ),
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: blog_third_width.
  $styles['blog_third_width'] = array(
    'label' => 'Blog third width',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 193,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'blog_third_width',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 193,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: fb_general.
  $styles['fb_general'] = array(
    'label' => 'FB general',
    'effects' => array(
      9 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'fb_general',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fb_link_image.
  $styles['fb_link_image'] = array(
    'label' => 'FB link image',
    'effects' => array(
      7 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 180,
          'height' => 180,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'fb_link_image',
        ),
        'weight' => 0,
      ),
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
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
