<?php
/**
 * @file
 * atom_person_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atom_person_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact_info|node|person|default';
  $field_group->group_name = 'group_person_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_person_email_address',
      1 => 'field_person_phone_number',
      2 => 'field_person_twitter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-person-contact-info field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_person_contact_info|node|person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact_info|node|person|form';
  $field_group->group_name = 'group_person_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_person_email_address',
      1 => 'field_person_phone_number',
      2 => 'field_person_twitter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-contact-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_person_contact_info|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact_info|node|person|full';
  $field_group->group_name = 'group_person_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_person_email_address',
      1 => 'field_person_phone_number',
      2 => 'field_person_twitter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-person-contact-info field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_person_contact_info|node|person|full'] = $field_group;

  return $export;
}
