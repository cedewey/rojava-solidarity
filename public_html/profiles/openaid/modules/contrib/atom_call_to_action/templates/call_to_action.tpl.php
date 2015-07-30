<?php
/**
 * @file
 * Call to action template
 */
?>
<?php if (!$has_image): ?>
  <section class="call-to-action call-to-action--text">
    <header>
      <h1><?php echo $title; ?></h1>
    </header>
    <div class="call-to-action-text">
      <?php echo $text; ?>
    </div>
    <?php if ($has_link): ?>
      <a href="<?php echo $link_url; ?>" class="button button--call-to-action"><?php echo $link_title; ?></a>
    <?php endif ?>
  </section>
<?php else: ?>
  <section class="call-to-action call-to-action--image">
    <?php if ($has_link): ?>
      <a href="<?php echo $link_url; ?>">
    <?php endif; ?>
    <?php echo $image; ?>
    <?php if ($has_link): ?>
      </a>
    <?php endif ?>
  </section>
<?php endif ?>
