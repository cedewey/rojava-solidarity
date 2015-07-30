<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>
<?php print $dev_deets; ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix project--full"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <h1 class="page-title"><?php print $title; ?></h1>
  <?php print render($title_suffix); ?>

  <div class="l--sidebar-after clearfix">
    <div class="l-secondary">
      <?php if (isset($content['field_person_photo'])): ?>
        <?php print render($content['field_person_photo']); ?>
      <?php endif; ?>
    </div>
    <div class="l-primary">
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_person_photo']);
        hide($content['field_person_photo']);
        print render($content);
      ?>
    </div>
  </div>

  <?php print render($content['links']); ?>
</article>
