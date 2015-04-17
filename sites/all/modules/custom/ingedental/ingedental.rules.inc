<?php

/**
 * Implements hook_rules_action_info()
 */
function ingedental_rules_action_info() {
  return array(
    'ingedental_post_to_twitter' => array(
      'label' => t('Post to Twitter'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Blog'),
          'description' => t('The blog containing the data to be published on twitter.'),
        ),
      ),
    ),
    'ingedental_concatenate_string' => array(
      'label' => t('Concatenate Strings'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'text1' => array(
          'type' => 'text',
          'label' => t('First string'),
          'description' => t('First string'),
          'sanitize' => FALSE,
          'decode' => FALSE,
          'default mode' => 'selector',
        ),
        'text2' => array(
          'type' => 'text',
          'label' => t('Second string'),
          'description' => t('Second string'),
          'sanitize' => FALSE,
          'decode' => FALSE,
          'default mode' => 'selector',
        ),
        'type' => array(
          'type' => 'integer',
          'label' => t('Type of Concatenation'),
          'options list' => '_concat_type',
          'description' => t('Type of Concatenation'),
          'default mode' => 'input',
        ),
      ),
      'provides' => array(
        'string' => array(
          'label' => 'Full string',
          'type' => 'text',
          'save' => FALSE,
        ),
      ),
    ),
    'ingedental_filter_string' => array(
      'label' => t('Strip tags from string'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'text' => array(
          'type' => 'text',
          'label' => t('string'),
          'description' => t('String'),
          'sanitize' => FALSE,
          'decode' => FALSE,
          'default mode' => 'selector',
        ),
      ),
      'provides' => array(
        'string' => array(
          'label' => 'Filtered string',
          'type' => 'text',
          'save' => FALSE,
        ),
      ),
    ),
    'ingedental_strip_image_urls' => array(
      'label' => t('Strip image URLs'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'text' => array(
          'type' => 'text',
          'label' => t('Text'),
          'description' => t('Text to strip images from.'),
          'sanitize' => FALSE,
          'decode' => FALSE,
        ),
      ),
      'provides' => array(
        'image_urls' => array(
          'label' => 'Image URLs',
          'type' => 'list<text>',
          'save' => FALSE,
        ),
      ),
    ),
    'ingedental_get_image_url' => array(
      'label' => t('Get image realpath'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'image' => array(
          'type' => 'integer',
          'label' => t('Image file id'),
          'description' => t('The image file id.'),
          'default mode' => 'selector',
        ),
        'image_cache_style' => array(
          'type' => 'text',
          'label' => t('Image cache style'),
          'description' => t('The Image cache style.'),
          'options list' => '_image_cache_styles',
          'default mode' => 'input',
        ),
      ),
      'provides' => array(
        'image_url' => array(
          'label' => 'Image URL',
          'type' => 'text',
          'save' => FALSE,
        ),
      ),
    ),
    'ingedental_get_image_url2' => array(
      'label' => t('Get image url'),
      'group' => t('IngeDental'),
      'parameter' => array(
        'image' => array(
          'type' => 'integer',
          'label' => t('Image file id'),
          'description' => t('The image file id.'),
          'default mode' => 'selector',
        ),
        'image_cache_style' => array(
          'type' => 'text',
          'label' => t('Image cache style'),
          'description' => t('The Image cache style.'),
          'options list' => '_image_cache_styles',
          'default mode' => 'input',
        ),
      ),
      'provides' => array(
        'image_url' => array(
          'label' => 'Image URL',
          'type' => 'text',
          'save' => FALSE,
        ),
      ),
    ),
    'ingedental_publish_photo_to_facebook' => array(
      'label' => t('Publish ID photo to Facebook page'),
      'group' => t('Facebook Autopost'),
      'parameter' => array(
        'publication' => array(
          'type' => 'facebook_publication',
          'label' => t('Facebook publication'),
        ),
        'pages' => array(
          'type' => 'text',
          'label' => t('Facebook pages'),
          'options list' => 'fb_autopost_entity_available_facebook_pages',
          'access callback' => 'can_administer_facebook_publications',
        ),
      ),
      'provides' => array(
        'facebook_publication_id' => array(
          'type' => 'text',
          'label' => t('Facebook publication returned ID'),
        ),
      ),
    ),
  );
}

function ingedental_post_to_twitter($node) {

  if ($node->field_post_to_twitter[LANGUAGE_NONE][0]['value'] && !empty($node->field_twitter_status[LANGUAGE_NONE][0]['value'])) {
    module_load_include('inc', 'twitter');

    $twitter_account = twitter_account_load($node->field_twitter_account[LANGUAGE_NONE][0]['value']);
    $replacements = array(
      '!title' => $node->title,
      '!url' => url('node/' . $node->nid, array('absolute' => TRUE, 'alias' => TRUE)),
      '!url-alias' => url('node/' . $node->nid, array('absolute' => TRUE)),
      '!user' => $node->name,
    );

    if (strstr($node->field_twitter_status[LANGUAGE_NONE][0]['value'], '!tinyurl') !== FALSE) {
      $replacements['!tinyurl'] = twitter_shorten_url(url('node/' . $node->nid, array('absolute' => TRUE)));
    }

    $status = strtr($node->field_twitter_status[LANGUAGE_NONE][0]['value'], $replacements);

    if (twitter_set_status($twitter_account, $status)) {
      drupal_set_message(t('Successfully posted to Twitter'));
    }
    else {
      drupal_set_message(t('Unuccessfully posted to Twitter'), 'warning');
    }

  }

}

function ingedental_concatenate_string($text1, $text2, $type) {
  switch ($type) {
  case 1:
    return array('string' => $text1 . " " . $text2);
    break;

  case 2:
    return array('string' => $text1 . "\r\n" . $text2);
    break;
  default:
  case 0:
    return array('string' => $text1 . $text2);
  }
}

function _concat_type() {
  return array(
    0 => 'Straight',
    1 => 'With a space',
    2 => 'With a newline',
  );
}

function ingedental_filter_string($text) {
  return array('string' => strip_tags($text));
}

function ingedental_strip_image_urls($text) {

  preg_match_all('~<img.*?src=["\']+(.*?)["\']+~', $text, $urls);
  $urls = $urls[1];

  foreach ($urls as $i => $j) {
    $t = explode('?', $j);
    $urls[$i] = $t[0];
  }

  return array('image_urls' => $urls);
}

function _image_cache_styles() {
  $return = array();

  foreach (image_styles() as $style) {
    $return[$style['name']] = $style['label'];
  }

  return $return;
}

function ingedental_get_image_url($fid, $image_cache_style) {
  $file = file_load( $fid );

  $uri = image_style_path($image_cache_style, $file->uri);

  return array('image_url' => drupal_realpath($uri));
}

function ingedental_get_image_url2($fid, $image_cache_style) {

  $url = '';
  $file = file_load( $fid );

  $uri = image_style_path($image_cache_style, $file->uri);

  return array('image_url' => file_create_url($uri));
}




/**
 * Callback function called when executing the action.
 */
function ingedental_publish_photo_to_facebook(FacebookPublicationEntity $publication, $pages) {
  try {
    $fb = new FBAutopostEntityIDPhoto();
    $facebook_returned_id = $fb->setDestination($pages)->publishEntity($publication);
    return array('facebook_publication_id' => $facebook_returned_id['id']);
  }
  catch (Exception $e) {
    watchdog_exception('fb_autopost', $e);
    drupal_set_message($e->getMessage(), 'error');
  }
}

