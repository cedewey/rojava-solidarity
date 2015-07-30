<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>
<?php print $dev_deets; ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> article--teaser clearfix"<?php print $attributes; ?>>
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

  <?php if (isset($content['field_blog_image'])): ?>
    <?php print render($content['field_blog_image']); ?>
  <?php endif; ?>

  <?php print render($title_prefix); ?>
  <h3 class="title"<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_blog_image']);
      print render($content);
    ?>
  </div>

  <?php print render($content['links']); ?>
</article>
