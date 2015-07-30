<?php

/**
 * @file
 * Image Gallery Teaser
 */

?>
<?php print $dev_deets; ?>
<a href="<?php print $node_url; ?>" class="link--article">
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> gallery--teaser clearfix"<?php print $attributes; ?> style="background-image: url(<?php echo $image_path; ?>);">
    <div class="gallery-content">
      <h3 class="title"<?php print $title_attributes; ?>><?php print $title; ?></h3>
      <div class="gallery-description">
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          hide($content['field_gallery_media_images']);
          print render($content);
        ?>
      </div>
    </div>
  </article>
</a>
