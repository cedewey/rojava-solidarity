<?php
/**
 * @file
 * atom_project_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function atom_project_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_project';
  $context->description = 'Adds Atom Project Highlights block';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'atom_project-atom_project_highlights' => array(
          'module' => 'atom_project',
          'delta' => 'atom_project_highlights',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
    'region' => array(
      'adminimal' => array(
        'disable' => array(
          'content_before' => 0,
          'sidebar_left' => 0,
          'content' => 0,
          'sidebar_right' => 0,
          'content_after' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'openaid2' => array(
        'disable' => array(
          'page_top' => 0,
          'page_bottom' => 0,
          'utility' => 0,
          'top_banner' => 0,
          'header' => 0,
          'navigation' => 0,
          'help' => 0,
          'marquee' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'above_content' => 0,
          'content' => 0,
          'sidebar' => 0,
          'below_content' => 0,
          'footer' => 0,
          'admin_footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds Atom Project Highlights block');
  t('type');
  $export['atom_project'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_project_latest_updates';
  $context->description = 'Add the latest updates block to projects';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'atom_project-atom_project_latest_updates' => array(
          'module' => 'atom_project',
          'delta' => 'atom_project_latest_updates',
          'region' => 'below_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add the latest updates block to projects');
  t('type');
  $export['atom_project_latest_updates'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_project_navigation';
  $context->description = 'Keeps the projects link active when viewing projects.';
  $context->tag = 'navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:projects',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Keeps the projects link active when viewing projects.');
  t('navigation');
  $export['atom_project_navigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atom_project_projects_page';
  $context->description = 'Adds the project map to the Projects page';
  $context->tag = 'page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'atom_projects:page' => 'atom_projects:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'atom_project-atom_project_map_block' => array(
          'module' => 'atom_project',
          'delta' => 'atom_project_map_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the project map to the Projects page');
  t('page');
  $export['atom_project_projects_page'] = $context;

  return $export;
}
