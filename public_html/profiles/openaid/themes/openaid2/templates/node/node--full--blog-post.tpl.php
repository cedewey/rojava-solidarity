<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>
<?php print $dev_deets; ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> article--full clearfix"<?php print $attributes; ?>>
  <footer class="dateline">
    <?php if (isset($content['blog_post_type'])): ?>
      <?php print render($content['blog_post_type']); ?>
    <?php endif; ?>
    <?php if (isset($content['blog_post_date'])): ?>
      <?php print render($content['blog_post_date']); ?>
    <?php endif; ?>
    <?php if (isset($content['field_blog_authors'])): ?>
      <?php print render($content['field_blog_authors']); ?>
    <?php endif; ?>
  </footer>

  <?php print render($title_prefix); ?>
  <h1 class="page-title"<?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php print render($title_suffix); ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
