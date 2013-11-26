<?php
/**
 * @file
 * imagex_splash_image.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function imagex_splash_image_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_body'
  $field_bases['field_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_body',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_splash'
  $field_bases['field_splash'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_splash',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'eck_media_asset' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'eck_media_asset',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'splash' => 'splash',
        ),
      ),
      'target_type' => 'media_asset',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
