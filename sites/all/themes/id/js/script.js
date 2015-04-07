/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  $(document).ready(function() {
    //console.log(Drupal);
    if($('#content #page-title').html() == 'Callie\'s Corner') {
      $('#content #page-title').prepend('<img style="float: right; width: 134px;" class="callies-corner-logo " src="' + Drupal.settings.basePath + Drupal.settings.theme.theme_path + '/images/callie_logo.png" alt="Callie\'s Corner" title="Callie\'s Corner" />');
    }
  });
})(jQuery, Drupal, this, this.document);
