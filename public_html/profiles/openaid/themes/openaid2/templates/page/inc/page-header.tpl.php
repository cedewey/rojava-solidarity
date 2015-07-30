<header id="header">
  <div class="l--constrained--padded clearfix">
    <div id="branding">
      <h1><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><?php if ($logo): ?><img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" /><?php elseif ($site_name): ?><?php print $site_name; ?><?php endif; ?></a></h1>
      <?php if ($site_slogan): ?>
        <h2 id="site-slogan">
         <?php print $site_slogan; ?>
        </h2>
      <?php endif; ?>
    </div>
    <?php if ($page['utility']): ?>
      <div id="utility">
        <?php print render($page['utility']); ?>
      </div>
    <?php endif; // end utility ?>
    <?php if ($page['header']): ?>
        <?php print render($page['header']); ?>
    <?php endif; // end header ?>
  </div>
</header>

<?php if ($main_menu): ?>
  <div id="navigation" class="clearfix">
    <div class="l--constrained">
    <?php print theme('links__system_main_menu', array(
      'links' => $main_menu,
      'attributes' => array(
        'id' => 'primary-menu',
        'class' => array('links', 'clearfix', 'nav'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    )); ?>
    <?php if ($page['navigation']): ?>
      <?php print render($page['navigation']); ?>
    <?php endif; ?>
    </div>
  </div> <!-- /#main-menu -->
<?php endif; ?>
