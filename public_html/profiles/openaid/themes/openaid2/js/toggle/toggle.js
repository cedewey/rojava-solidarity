(function($){

  var toggle = function(config) {
    /**
     * Settings
     */
    var settings = {
          button: $('<button class="button--toggle"></button>'),
          collapsed: true,
          on_content: 'Collapse',
          off_content: 'Expand',
          on_target: null,
          off_target: null,
          insert_method: 'append',
          container: null,
          update_button: true,
          on_click: function(){}
        },
        debug = false;

    /**
     * Perform setup.
     */
    var init = function(config) {
      $.extend(true, settings, config);
      s = settings;
      log('Initialize toggle.js');

      s.on_target = s.on_target || s.container;

      bindUI();

      if (s.insert_method) {
        s.container[s.insert_method](s.button);
      }

      if (s.collapsed) {
        s.button.trigger('collapse');
      }

      return {
        settings: s,
        button: $(s.button),
        collapse: function() {this.button.trigger('collapse')},
        expand: function() {this.button.trigger('expand')}
      };
    };

    /**
     * Bind events to the UI.
     */
    var bindUI = function() {
      var s = settings,
          $button = s.button,
          collapse = s.collapsed,
          $on_target = s.on_target,
          $off_target = s.off_target;

      log("binding events");

      // Bind event handlers to the button.
      $button.bind({
        click: buttonClick,
        touchstart: buttonClick,
        collapse: buttonCollapse,
        expand: buttonExpand
      });

      collapse ? $button.trigger('collapse') : $button.trigger('expand');

      $on_target.bind({
        collapse: targetCollapse,
        expand: targetExpand
      });

      collapse ? $on_target.trigger('collapse') : $on_target.trigger('expand');

      if ($off_target !== null) {
        $off_target.bind({
          collapse: targetCollapse,
          expand: targetExpand
        });

        collapse ? $off_target.trigger('expand') : $off_target.trigger('collapse');
      }
    };

    var buttonClick = function(event) {
      var $this = $(this);
      log($this.data('aria-expanded'));
      $this.data('aria-expanded') ?
        $this.trigger('collapse') :
        $this.trigger('expand');

      settings.on_click();
      event.stopPropagation();
      return false;
    };

    var buttonCollapse = function(event) {
      var s = settings,
          $this = $(this),
          $off_target = s.off_target,
          $on_target = s.on_target;
      log('collapsing button');
      $this.data('aria-expanded', false)
        .attr('aria-expanded', false);

      if (s.update_button) {
        $this.html(s.off_content);
      }

      log('trigger target collapse on');
      log($on_target);
      $on_target.trigger('collapse');

      if ($off_target !== null) {
        $off_target.trigger('expand');
      }
    };

    var buttonExpand = function(event) {
      var s = settings,
          $this = $(this),
          $off_target = s.off_target,
          $on_target = s.on_target;

      $this.data('aria-expanded', true)
        .attr('aria-expanded', true);

      if (s.update_button) {
        $this.html(s.on_content);
      }

      $on_target.trigger('expand');

      if ($off_target !== null) {
        $off_target.trigger('collapse');
      }
    };

    var targetCollapse = function(event) {
      log('collapsing target');

      $(this).data('aria-expanded', false)
        .attr('aria-expanded', false);
    };

    var targetExpand = function(event) {
      $(this).data('aria-expanded', true)
        .attr('aria-expanded', true);
    };

    /**
     * Debug aware logging.
     */
    var log = function() {
      // only if we are in debug mode
      if (!debug) { return; }

      // only if we have console.log
      if (typeof console !== 'undefined' && typeof console.log !== 'undefined') {
        console.log.apply(console, arguments);
      }
    };

    return init(config);
  };

  this.toggle = toggle;

})(jQuery);
