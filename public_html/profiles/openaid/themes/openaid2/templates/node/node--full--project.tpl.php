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
    <div class="l-primary">
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['group_project_meta']);
        hide($content['field_project_image']);
        print render($content);
      ?>
    </div>
    <div class="l-secondary block--meta">
      <?php if (isset($content['field_project_image'])): ?>
        <?php print render($content['field_project_image']); ?>
      <?php endif; ?>
      <?php if (isset($content['group_project_meta'])): ?>
        <?php print render($content['group_project_meta']); ?>
      <?php endif; ?>
    </div>
  </div>

  <?php print render($content['links']); ?>
</article>
