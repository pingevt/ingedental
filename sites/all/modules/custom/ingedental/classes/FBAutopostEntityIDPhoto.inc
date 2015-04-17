<?php

/**
 * @file
 * Class implementation for FBAutopostEntityPhoto
 */

/**
 * Special case for FacebookPublicationType Photo
 */
class FBAutopostEntityIDPhoto extends FBAutopostEntity {
  /**
   * Prepares the parameters to publish to Facebook, this means settings any
   * field or destination dependent configuration.
   */
  protected function publishParameterPrepare(&$publication) {
    parent::publishParameterPrepare($publication);
    // Add facebook support for uploading files
    $this->setFileUploadSupport(true);
    // Add @ in front of upload URL
    $publication['params']['source'] = '@' . $publication['params']['source'];

  }
}
