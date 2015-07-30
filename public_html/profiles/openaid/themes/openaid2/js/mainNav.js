(function ($, toggle) {

  var mainNav = {
    mainNavToggle: {},
    header: {},

    // mainNav setup.
    init: function() {
      mainNav.header = $('#header');
      mainNav.branding = $('#branding');
      mainNav.utility = $('#utility');
      mainNav.nav = $('#navigation');
      mainNav.flyoutInner = $('<div id="flyout-inner"></div>');
      mainNav.flyout = $('<div id="flyout"></div>').append(mainNav.flyoutInner);

      // Initialize the menu toggle.
      mainNavToggle = toggle({
        button: $('<button class="header-toggle" aria-controls="flyout">Menu <span class="header-toggle-icon"></span></button>'),
        container: mainNav.flyout,
        update_button: false,
        insert_method: 'prepend',
        on_click: function() {
          window.scrollTo(0, 0);
        }
      });

      mainNav.bindUI();

      mainNav.header.append(mainNav.flyout);

      // Add a class if transforms are supported.
      mainNav.getSupportedTransform() ?
        $('html').addClass('css-transforms') :
        $('html').addClass('no-css-transforms');

      mainNav.adminMenuFix();
    },

    bindUI: function() {
      var $window = $(window);

      // Bind Window events.
      $window.bind('load resize orientationchange', function(){
        mainNav.testFit();
      });

      // Bind Window events.
      $window.bind('click', function(){
        mainNavToggle.collapse();
      });

      // Prevent Bubbling.
      mainNav.flyoutInner.bind('click', function(event){
        event.stopPropagation();
      });
    },

    testFit: function(){
      var items = mainNav.nav.find('.nav-link'),
          $window = $(window);

      $('body').removeClass('has-flyout');
      mainNav.header.after(mainNav.nav);
      mainNav.branding.after(mainNav.utility);

      // When options are stacked, display the nav as a menu
      if ( $(items[items.length-1]).offset().top > $(items[0]).offset().top ) {
        // show the menu -- add a class for scoping menu styles
        $('body').addClass('has-flyout');
        mainNav.flyoutInner.append(mainNav.utility).append(mainNav.nav);
        mainNav.flyout.width($window.width()).height($window.height());
      }
    },

    getSupportedTransform: function () {
      var prefixes = 'transform WebkitTransform MozTransform OTransform msTransform'.split(' ');
      for(var i = 0; i < prefixes.length; i++) {
        if(document.createElement('div').style[prefixes[i]] !== undefined) {
          return prefixes[i];
        }
      }
      return false;
    },

    adminMenuFix: function() {
      if($("body").hasClass("admin-menu")) {
        $(window).load( function() {
          mainNav.adminHeight();
        });
        $(window).resize( function() {
          mainNav.adminHeight();
        });
      }
    },

    adminHeight: function () {
      var $adminHeight = $("#admin-menu").height();
      $("body.admin-menu").attr("style", "margin-top: " + $adminHeight + "px !important");
    }
  };

  this.mainNav = mainNav;
})(jQuery, toggle);
