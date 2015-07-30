<?php
/**
 * Atom Project Sample Content Migration
 *
 * Provides some sample projects
 */
class AtomProjectSampleContentMigration extends DynamicMigration {
  /**
   * Constructor
   */
  public function __construct() {
    parent::__construct();

    $this->description = t('Import project content');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Project ID',
          'alias' => 'e',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // id,title,field_project_contact_email,field_project_contact_name,
    // field_project_contact_phone,field_project_description,
    // field_project_image,field_project_link_twitter,
    // field_project_link_facebook,field_project_location_lat,
    // field_project_location_lon,field_project_website
    $columns = array(
      0 => array('id', 'ID'),
      1 => array('title', 'Title'),
      2 => array('field_project_contact_email', 'Email'),
      3 => array('field_project_contact_name', 'Name'),
      4 => array('field_project_contact_phone', 'Phone'),
      5 => array('field_project_description', 'Description'),
      6 => array('field_project_image', 'Image'),
      7 => array('field_project_link_twitter', 'Twitter'),
      8 => array('field_project_link_facebook', 'Facebook'),
      9 => array('field_project_location_lat', 'Lat'),
      10 => array('field_project_location_lon', 'Lon'),
      11 => array('field_project_website', 'Website'),
    );

    $this->source = new MigrateSourceCSV(
      drupal_get_path('module', 'atom_project_sample_content') . '/project.csv',
      $columns,
      array('header_rows' => 1)
    );
    $this->destination = new MigrateDestinationNode('project');

    // mappings
    $this->addSimpleMappings(array(
      'title',
      'field_project_contact_email',
      'field_project_contact_name',
      'field_project_contact_phone',
      'field_project_description',
      'field_project_image',
    ));

    // twitter
    $this->addFieldMapping('field_project_link_twitter:title')->defaultValue('Twitter');
    $this->addFieldMapping('field_project_link_twitter:url', 'field_project_link_twitter');

    // facebook
    $this->addFieldMapping('field_project_link_facebook:title')->defaultValue('Facebook');
    $this->addFieldMapping('field_project_link_facebook:url', 'field_project_link_facebook');

    // website
    $this->addFieldMapping('field_project_website:title')->defaultValue('Example');
    $this->addFieldMapping('field_project_website:url', 'field_project_website');

    // status
    $this->addFieldMapping('status')->defaultValue(1);
  }

  /**
   * Prepare the entity
   *
   * Manually adds the location data.
   */
  public function prepare($entity, $row) {
    // manually add the location data because migrate_extras/geofield doesn't
    // work with the this anymore (or requires way more work than this).
    $data = array(
      'lat' => floatval($row->field_project_location_lat),
      'lon' => floatval($row->field_project_location_lon),
    );
    geofield_compute_values($data, 'latlon');
    $entity->field_project_location = array(
      LANGUAGE_NONE => array(
        $data,
      ),
    );
  }

}
