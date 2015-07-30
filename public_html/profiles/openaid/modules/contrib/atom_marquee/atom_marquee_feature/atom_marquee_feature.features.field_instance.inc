<?php
/**
 * @file
 * atom_marquee_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function atom_marquee_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-marquee-field_marquee_image'
  $field_instances['node-marquee-field_marquee_image'] = array(
    'bundle' => 'marquee',
    'deleted' => 0,
    'description' => '<ul>
<li>Upload an image to use for the marquee.</li>
<li>Images will be resized to 1400x474.</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'atom_marquee',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marquee_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'marquee-images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '1400x474',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-marquee-field_marquee_link'
  $field_instances['node-marquee-field_marquee_link'] = array(
    'bundle' => 'marquee',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul>
<li>Enter a relative (eg: about-us) or absolute (eg: http://www.duckduckgo.com) link.</li>
<li>The title is the action you want the user to take (eg: Learn More, Check it Out)</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marquee_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-marquee-field_marquee_text'
  $field_instances['node-marquee-field_marquee_text'] = array(
    'bundle' => 'marquee',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a short summary.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marquee_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<ul>
<li>Enter a relative (eg: about-us) or absolute (eg: http://www.duckduckgo.com) link.</li>
<li>The title is the action you want the user to take (eg: Learn More, Check it Out)</li>
</ul>');
  t('<ul>
<li>Upload an image you to use for the marquee.</li>
<li>Images will be resized to 1400x474.</li>
</ul>');
  t('Enter a short summary.');
  t('Image');
  t('Link');
  t('Text');

  return $field_instances;
}
