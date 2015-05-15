<?php
/**
 * @file
 * ingedental_blog.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ingedental_blog_default_rules_configuration() {
  $items = array();
  $items['rules_flush_caches_after_scheduler'] = entity_import('rules_config', '{ "rules_flush_caches_after_scheduler" : {
      "LABEL" : "Flush Caches after scheduler",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "scheduler" ],
      "ON" : { "scheduler_node_has_been_published_event" : [] },
      "DO" : [
        { "php_eval" : { "code" : "\\/\\/ define static var\\r\\ndefine(\\u0027DRUPAL_ROOT\\u0027, getcwd());\\r\\n\\/\\/ include bootstrap\\r\\ninclude_once(\\u0027.\\/includes\\/bootstrap.inc\\u0027);\\r\\n\\/\\/ initialize stuff\\r\\ndrupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);\\r\\n\\/\\/ clear cache\\r\\ndrupal_flush_all_caches();" } }
      ]
    }
  }');
  $items['rules_post_link_to_facebook'] = entity_import('rules_config', '{ "rules_post_link_to_facebook" : {
      "LABEL" : "Post Link to facebook",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "add blog", "facebook", "link" ],
      "REQUIRES" : [ "rules", "ingedental", "fb_autopost_entity" ],
      "ON" : { "node_insert--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-link-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "link",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-link" ],
            "value" : [ "node:url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-description" ],
            "value" : [ "node:field-fb-link-description" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "node:field-fb-link-message" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-name" ],
            "value" : [ "node:title" ]
          }
        },
        { "ingedental_get_image_url2" : {
            "USING" : {
              "image" : [ "node:field-link-image:file:fid" ],
              "image_cache_style" : "fb_link_image"
            },
            "PROVIDE" : { "image_url" : { "image_url" : "Image URL" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-picture" ],
            "value" : [ "image-url" ]
          }
        },
        { "publish_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_link_to_facebook_update'] = entity_import('rules_config', '{ "rules_post_link_to_facebook_update" : {
      "LABEL" : "Post Link to Facebook (update)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "facebook", "link", "update blog" ],
      "REQUIRES" : [ "rules", "ingedental", "fb_autopost_entity" ],
      "ON" : { "node_update--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-link-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "link",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-link" ],
            "value" : [ "node:url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-description" ],
            "value" : [ "node:field-fb-link-description" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "node:field-fb-link-message" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-name" ],
            "value" : [ "node:title" ]
          }
        },
        { "ingedental_get_image_url2" : {
            "USING" : {
              "image" : [ "node:field-link-image:file:fid" ],
              "image_cache_style" : "fb_link_image"
            },
            "PROVIDE" : { "image_url" : { "image_url" : "Image URL" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-picture" ],
            "value" : [ "image-url" ]
          }
        },
        { "publish_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_photo_to_facebook'] = entity_import('rules_config', '{ "rules_post_photo_to_facebook" : {
      "LABEL" : "Post photo to Facebook",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "add blog", "Facebook", "photo" ],
      "REQUIRES" : [ "rules", "ingedental" ],
      "ON" : { "node_insert--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-photo-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "photo",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "ingedental_get_image_url" : {
            "USING" : {
              "image" : [ "node:field-fb-image:file:fid" ],
              "image_cache_style" : "fb_general"
            },
            "PROVIDE" : { "image_url" : { "image_url" : "Image URL" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-source" ],
            "value" : [ "image-url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "node:field-fb-image-message" ]
          }
        },
        { "ingedental_publish_photo_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_photo_to_facebook_update'] = entity_import('rules_config', '{ "rules_post_photo_to_facebook_update" : {
      "LABEL" : "Post photo to Facebook (update)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Facebook", "photo", "update blog" ],
      "REQUIRES" : [ "rules", "ingedental" ],
      "ON" : { "node_update--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-photo-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "photo",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "ingedental_get_image_url" : {
            "USING" : {
              "image" : [ "node:field-fb-image:file:fid" ],
              "image_cache_style" : "fb_general"
            },
            "PROVIDE" : { "image_url" : { "image_url" : "Image URL" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-source" ],
            "value" : [ "image-url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "node:field-fb-image-message" ]
          }
        },
        { "ingedental_publish_photo_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_post_to_facebook'] = entity_import('rules_config', '{ "rules_post_post_to_facebook" : {
      "LABEL" : "Post post to Facebook (update)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "facebook", "post", "update blog" ],
      "REQUIRES" : [ "rules", "ingedental", "fb_autopost_entity" ],
      "ON" : { "node_update--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-post-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "post",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "ingedental_filter_string" : {
            "USING" : { "text" : [ "node:body:value" ] },
            "PROVIDE" : { "string" : { "filtered_string" : "Filtered string" } }
          }
        },
        { "ingedental_concatenate_string" : {
            "USING" : {
              "text1" : [ "filtered-string" ],
              "text2" : [ "node:field-append-to-body" ],
              "type" : "0"
            },
            "PROVIDE" : { "string" : { "string" : "Full string" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "string" ]
          }
        },
        { "publish_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_post_to_facebook_add'] = entity_import('rules_config', '{ "rules_post_post_to_facebook_add" : {
      "LABEL" : "Post post to Facebook",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "add blog", "Facebook", "post" ],
      "REQUIRES" : [ "rules", "ingedental", "fb_autopost_entity" ],
      "ON" : { "node_insert--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-add-post-to-facebook" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "post",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "ingedental_filter_string" : {
            "USING" : { "text" : [ "node:body:value" ] },
            "PROVIDE" : { "string" : { "filtered_string" : "Filtered string" } }
          }
        },
        { "ingedental_concatenate_string" : {
            "USING" : {
              "text1" : [ "filtered-string" ],
              "text2" : [ "node:field-append-to-body" ],
              "type" : "0"
            },
            "PROVIDE" : { "string" : { "string" : "Full string" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "string" ]
          }
        },
        { "publish_to_facebook" : {
            "USING" : {
              "publication" : [ "entity-created" ],
              "pages" : [ "node:field-facebook-page" ]
            },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:facebook-id" ],
            "value" : [ "facebook-publication-id" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_post_to_twitter'] = entity_import('rules_config', '{ "rules_post_to_twitter" : {
      "LABEL" : "Post to Twitter",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "add blog", "Twitter" ],
      "REQUIRES" : [ "rules", "ingedental" ],
      "ON" : { "node_insert--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-post-to-twitter" ], "value" : "1" } }
      ],
      "DO" : [ { "ingedental_post_to_twitter" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_post_to_twitter_update'] = entity_import('rules_config', '{ "rules_post_to_twitter_update" : {
      "LABEL" : "Post to Twitter (update)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Twitter", "update blog" ],
      "REQUIRES" : [ "rules", "ingedental" ],
      "ON" : { "node_update--blog_entry" : { "bundle" : "blog_entry" } },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [ { "ingedental_post_to_twitter" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
