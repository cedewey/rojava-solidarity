<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>
<?php print $dev_deets; ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> marquee--teaser"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <div class="l--constrained">
    <div class="marquee-content"<?php print $content_attributes; ?>>
      <?php if (isset($content['field_marquee_text'])): ?>
        <?php print render($content['field_marquee_text']); ?>
      <?php endif; ?>
      <?php if (isset($content['field_marquee_link'])): ?>
        <?php print render($content['field_marquee_link']); ?>
      <?php endif; ?>

      <?php
        hide($content['comments']);
        hide($content['links']);
        // We hide the image because we enject it as a background image with CSS.
        hide($content['field_marquee_image']);
        print render($content);
      ?>
    </div>
  </div>
</article>
