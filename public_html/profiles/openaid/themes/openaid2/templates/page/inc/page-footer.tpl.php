<div id="footer" class="l--constrained--padded clearfix">
  <?php if ($footer_logo): ?><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="footer-logo"><img src="<?php print $footer_logo; ?>" alt="<?php print $site_name; ?>" /></a><?php endif; ?>
  <div class="footer-inner">
    <?php print render($page['footer']); ?>
    <p class="copyright"><?php echo check_plain(openaid2_get_setting('copyright', openaid2_default_copyright())); ?></p>
  </div>
</div>

<?php if ($page['admin_footer']): ?>
  <div id="admin-footer" class="l--constrained">
    <?php print render($page['admin_footer']); ?>
  </div>
<?php endif; // end admin_footer ?>
