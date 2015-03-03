(function($) {

/**
 * jQuery debugging helper.
 *
 * Invented for Dreditor.
 *
 * @usage
 *   $.debug(var [, name]);
 *   $variable.debug( [name] );
 */
jQuery.extend({
  debug: function () {
    // Setup debug storage in global window. We want to look into it.
    window.debug = window.debug || [];

    args = jQuery.makeArray(arguments);
    // Determine data source; this is an object for $variable.debug().
    // Also determine the identifier to store data with.
    if (typeof this == 'object') {
      var name = (args.length ? args[0] : window.debug.length);
      var data = this;
    }
    else {
      var name = (args.length > 1 ? args.pop() : window.debug.length);
      var data = args[0];
    }
    // Store data.
    window.debug[name] = data;
    // Dump data into Firebug console.
    if (typeof console != 'undefined') {
      console.log(name, data);
    }
    return this;
  }
});
// @todo Is this the right way?
jQuery.fn.debug = jQuery.debug;

})(jQuery);
;
/**
 * @file
 * Loads report blocks via ajax.  This is done because the API requests to Google
 * Analytics can add signifigant latency to page loads otherwise.
 */
(function ($) {

Drupal.behaviors.googleAnalyticsReports = {
  attach: function (context, settings) {
    $('#block-google-analytics-reports-path-mini,#block-google-analytics-reports-dashboard', context).show();

    if ($('.google-analytics-reports-path-mini', context).length) {
      $.ajax({
        url: Drupal.settings.googleAnalyticsReportsAjaxUrl + '/path-mini',
        dataType: 'json',
        data: ({ path: window.location.pathname + window.location.search }),
        success: function(data) {
          $('.google-analytics-reports-path-mini', context).html(data.content).hide().slideDown('fast');
        },
        error: function(data) {
          // @TODO
        }
      });
    }

    if ($('.google-analytics-reports-dashboard', context).length) {
      $.ajax({
        url: Drupal.settings.googleAnalyticsReportsAjaxUrl + '/dashboard',
        dataType: 'json',
        success: function(data) {
          $('.google-analytics-reports-dashboard', context).html(data.content).hide().slideDown('fast');
        },
        error: function(data) {
          // @TODO
        }
      });
    }
  }
}

})(jQuery);;
