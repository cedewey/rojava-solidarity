<?php

/**
 * Creates text fields that can be saved to content types.
 *
 * @code
 * $my_field = CINC::init('FieldCollectionField')->set('field_name', 'my_field');
 * @endcode
 */
class CINC_FieldCollectionField extends CINC_Field {

  function __construct() {

    parent::__construct();

    $this
      ->set('type', 'field_collection')
      ->set('module', 'field_collection');

    $this
      ->set_instance('widget', array(
        'type' => 'field_collection_embed',
      ));

  }

}
