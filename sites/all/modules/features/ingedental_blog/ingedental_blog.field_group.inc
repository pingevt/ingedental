<?php
/**
 * @file
 * ingedental_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ingedental_blog_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_image|node|blog_entry|form';
  $field_group->group_name = 'group_fb_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sm_facebook';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '40',
    'children' => array(
      0 => 'field_add_photo_to_facebook',
      1 => 'field_fb_image',
      2 => 'field_fb_image_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-fb-image field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_fb_image|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_link|node|blog_entry|form';
  $field_group->group_name = 'group_fb_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sm_facebook';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '41',
    'children' => array(
      0 => 'field_add_link_to_facebook',
      1 => 'field_fb_link_message',
      2 => 'field_fb_link_description',
      3 => 'field_link_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fb-link field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_fb_link|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fb_post|node|blog_entry|form';
  $field_group->group_name = 'group_fb_post';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sm_facebook';
  $field_group->data = array(
    'label' => 'Post',
    'weight' => '39',
    'children' => array(
      0 => 'field_add_post_to_facebook',
      1 => 'field_append_to_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fb-post field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_fb_post|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sm_facebook|node|blog_entry|form';
  $field_group->group_name = 'group_sm_facebook';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_social_media';
  $field_group->data = array(
    'label' => 'Facebook',
    'weight' => '15',
    'children' => array(
      0 => 'field_facebook_page',
      1 => 'group_fb_link',
      2 => 'group_fb_post',
      3 => 'group_fb_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sm-facebook field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sm_facebook|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sm_twitter|node|blog_entry|form';
  $field_group->group_name = 'group_sm_twitter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_social_media';
  $field_group->data = array(
    'label' => 'Twitter',
    'weight' => '14',
    'children' => array(
      0 => 'field_post_to_twitter',
      1 => 'field_twitter_status',
      2 => 'field_twitter_account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sm-twitter field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sm_twitter|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media|node|blog_entry|form';
  $field_group->group_name = 'group_social_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '6',
    'children' => array(
      0 => 'group_sm_twitter',
      1 => 'group_sm_facebook',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_media|node|blog_entry|form'] = $field_group;

  return $export;
}
