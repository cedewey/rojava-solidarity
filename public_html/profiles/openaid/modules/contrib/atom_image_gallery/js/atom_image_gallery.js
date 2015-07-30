
/**
 * Enable Boxer for image galleries
 */
(function($, Drupal) {

  var gallery = {
    // set to allow debugging or turn off to disallow. this does not
    // have a js_debug collary (because this happens in the admin).
    debug: true,
    current_type: null,

    /**
     * Initialize gallery js functionality
     */
    init: function() {
      var self = gallery;
      self.log('gallery[init]');

      // $('.boxer').boxer();
      $('.boxer').boxer({
        mobile: true
      });
      console.log('running');
    },

    /**
     * Debug aware logging
     */
    log: function() {
      // only if we are in debug mode
      if (!this.debug) { return; }

      // only if we have console.log
      if (typeof console !== 'undefined' && typeof console.log !== 'undefined') {
        console.log.apply(console, arguments);
      }
    },

  };

  $(document).ready(gallery.init);

})(jQuery, Drupal);
