<div id="page" class="<?php print $classes; ?>">

  <?php include('inc/page-header.tpl.php'); ?>

  <div id="main">
    <?php if ($messages): ?>
      <div id="messages" class="clearfix">
        <?php print $messages; ?>
      </div>
    <?php endif; // end messages ?>

    <?php if ($page['marquee']): ?>
      <div id="marquee">
        <?php print render($page['marquee']); ?>
      </div>
    <?php endif; // end marquee ?>

    <?php if ($page['highlighted']): ?>
      <div id="highlighted" class="clearfix">
        <div class="l--constrained--padded">
          <?php print render($page['highlighted']); ?>
        </div>
      </div>
    <?php endif; // end highlighted ?>

    <?php if ($page['featured']): ?>
      <div id="featured">
        <div class="l--constrained--padded">
          <?php print render($page['featured']); ?>
        </div>
      </div>
    <?php endif; // end featured ?>

    <div id="main-content" class="clearfix l--constrained--padded l--sidebar-after">
      <?php if ($page['subnav']): ?>
        <div id="subnav" class="l-secondary">
          <?php print render($page['subnav']); ?>
        </div>
      <?php endif; // end subnav ?>
      <div id="content" class="l-primary region--content">

        <?php if ($page['above_content']): ?>
          <div id="above-content">
            <?php print render($page['above_content']); ?>
          </div>
        <?php endif; // end Above Content ?>

        <?php if ($show_title && strlen($title) > 0): ?>
          <h1 <?php if (!empty($title_attributes)) print $title_attributes ?>>
            <?php print $title; ?>
          </h1>
        <?php endif; ?>

        <?php if ($page['help']): ?>
          <div id="help">
            <?php print render($page['help']); ?>
          </div>
        <?php endif; // end help ?>

        <?php if (render($tabs)): ?>
          <div id="tabs">
            <?php print render($tabs); ?>
          </div>
        <?php endif; // end tabs ?>

        <?php print render($page['content']); ?>
      </div>
      <?php if ($page['sidebar']): ?>
        <div id="sidebar" class="l-secondary">
          <?php print render($page['sidebar']); ?>
        </div>
      <?php endif; // end sidebar ?>
    </div>

    <?php if ($page['below_content']): ?>
      <div id="below-content" class="l--constrained--padded">
        <?php print render($page['below_content']); ?>
      </div>
    <?php endif; // end Below Content ?>
  </div>
  <?php include('inc/page-footer.tpl.php'); ?>

</div>
