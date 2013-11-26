<?php
/**
 * @file
 * imagex_splash_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function imagex_splash_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function imagex_splash_image_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function imagex_splash_image_eck_bundle_info() {
  $items = array(
  'media_asset_splash' => array(
  'machine_name' => 'media_asset_splash',
  'entity_type' => 'media_asset',
  'name' => 'splash',
  'label' => 'Splash',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function imagex_splash_image_eck_entity_type_info() {
$items = array(
       'media_asset' => array(
  'name' => 'media_asset',
  'label' => 'Media Asset',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'created' => array(
      'label' => 'Created',
      'type' => 'integer',
      'behavior' => 'created',
    ),
    'changed' => array(
      'label' => 'Changed',
      'type' => 'integer',
      'behavior' => 'changed',
    ),
  ),
),
  );
  return $items;
}

/**
 * Implements hook_image_default_styles().
 */
function imagex_splash_image_image_default_styles() {
  $styles = array();

  // Exported image style: flexslider_1200x350.
  $styles['flexslider_1200x350'] = array(
    'name' => 'flexslider_1200x350',
    'label' => 'flexslider_1200x300',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: flexslider_172x144.
  $styles['flexslider_172x144'] = array(
    'name' => 'flexslider_172x144',
    'label' => 'flexslider_174x144',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 174,
          'height' => 144,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: flexslider_588x290.
  $styles['flexslider_588x290'] = array(
    'name' => 'flexslider_588x290',
    'label' => 'flexslider_780x350',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 780,
          'height' => 350,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
