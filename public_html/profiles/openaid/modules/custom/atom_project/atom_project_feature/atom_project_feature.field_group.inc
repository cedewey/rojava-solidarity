<?php
/**
 * @file
 * atom_project_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atom_project_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_contact|node|project|form';
  $field_group->group_name = 'group_project_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_project_contact_email',
      1 => 'field_project_contact_name',
      2 => 'field_project_contact_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_contact|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_links|node|project|form';
  $field_group->group_name = 'group_project_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_project_link_facebook',
      1 => 'field_project_link_twitter',
      2 => 'field_project_links',
      3 => 'field_project_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-links field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_links|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_links|node|project|full';
  $field_group->group_name = 'group_project_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '0',
    'children' => array(
      0 => 'field_project_link_facebook',
      1 => 'field_project_link_twitter',
      2 => 'field_project_website',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 0,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-project-links field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_project_links|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_meta_contact|node|project|full';
  $field_group->group_name = 'group_project_meta_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_project_meta';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_project_contact_name',
      1 => 'field_project_contact_email',
      2 => 'field_project_contact_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-project-meta-contact field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_meta_contact|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_meta|node|project|full';
  $field_group->group_name = 'group_project_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_image',
      1 => 'group_project_meta_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-project-meta field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_project_meta|node|project|full'] = $field_group;

  return $export;
}
