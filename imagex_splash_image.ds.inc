<?php
/**
 * @file
 * imagex_splash_image.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function imagex_splash_image_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'media_asset|splash|default';
  $ds_layout->entity_type = 'media_asset';
  $ds_layout->bundle = 'splash';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_body',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['media_asset|splash|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'media_asset|splash|teaser';
  $ds_layout->entity_type = 'media_asset';
  $ds_layout->bundle = 'splash';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['media_asset|splash|teaser'] = $ds_layout;

  return $export;
}
