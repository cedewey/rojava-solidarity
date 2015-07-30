/**
 * Mirror the image option to a hidden field.
 */
(function($, Drupal) {

  "use strict";

  function update(element) {
    var $this = $(element);
    if ($this.is(':checked')) {
      $('input[name="atom_hero_image_options"]').val($this.val());
      if ($this.val() == 'map') {
        $('#edit-atom-hero-image-image-ajax-wrapper').hide();
      }
      else {
        $('#edit-atom-hero-image-image-ajax-wrapper').show();
      }
    }
  }

  Drupal.behaviors.atomHeroConfiguration = {
    attach: function(context) {
      update($('input[name="atom_hero_image_option"]:radio:checked'));
      $('input[name="atom_hero_image_option"]:radio').once('atomHeroConfiguration', function() {
        $(this).bind('click change', function() {
          update($(this));
        });
      });
    }
  };

})(jQuery, Drupal);
