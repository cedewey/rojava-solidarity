<?php
/**
 * @file
 * Project/Image Gallery template
 */
?>
<div class="atom-project-highlights--image-gallery gallery--teaser" style="background-image: url(<?php echo $image_path; ?>);">
  <div class="gallery-content">
    <h3 class="title"><?php echo l($gallery->title, 'node/' . $gallery->nid); ?></h3>
    <?php if ($description): ?>
      <div class="gallery-description"><?php echo $description; ?></div>
    <?php endif ?>
    <div class="gallery-links">
      <?php echo l(t('View Gallery'), 'node/' . $gallery->nid); ?> |
      <?php echo l(t('View All'), 'photos', array('query' => array('project' => $project->nid))); ?>
    </div>
  </div>
</div>
