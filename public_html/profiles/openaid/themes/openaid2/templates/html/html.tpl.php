<!DOCTYPE html>
<!--[if lt IE 7]> <html class="lt-ie9 lt-ie8 lt-ie7" lang="en"> <![endif]-->
<!--[if IE 7]>    <html class="lt-ie9 lt-ie8" lang="en"> <![endif]-->
<!--[if IE 8]>    <html class="lt-ie9" lang="en"> <![endif]-->
<!--[if gt IE 8]><!--> <html lang="en"> <!--<![endif]-->
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php
    if (theme_get_setting('toggle_favicon')) {
      $favicon = theme_get_setting('favicon');
    }
    else {
      $favicon = "/sites/all/themes/center/images/favicon.ico";
    }
  ?>
  <link rel="shortcut icon" type="image/x-icon" href="<?php print $favicon; ?>" />
  <?php print $styles; ?>
  <link href='http://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic' rel='stylesheet' type='text/css'>
  <?php print $scripts; ?>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php
    print $page_top;
    print $page;
    print $page_bottom;
  ?>
</body>
</html>
