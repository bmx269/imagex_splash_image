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
    'media_asset_carousel' => array(
      'machine_name' => 'media_asset_carousel',
      'entity_type' => 'media_asset',
      'name' => 'carousel',
      'label' => 'Carousel',
    ),
    'media_asset_carousel_item' => array(
      'machine_name' => 'media_asset_carousel_item',
      'entity_type' => 'media_asset',
      'name' => 'carousel_item',
      'label' => 'Carousel Item',
    ),
    'media_asset_slideshow' => array(
      'machine_name' => 'media_asset_slideshow',
      'entity_type' => 'media_asset',
      'name' => 'slideshow',
      'label' => 'Slideshow',
    ),
    'media_asset_splash' => array(
      'machine_name' => 'media_asset_splash',
      'entity_type' => 'media_asset',
      'name' => 'splash',
      'label' => 'Splash',
    ),
    'media_asset_testimonial_item' => array(
      'machine_name' => 'media_asset_testimonial_item',
      'entity_type' => 'media_asset',
      'name' => 'testimonial_item',
      'label' => 'Testimonial Item',
    ),
    'media_asset_testimonial_slideshow' => array(
      'machine_name' => 'media_asset_testimonial_slideshow',
      'entity_type' => 'media_asset',
      'name' => 'testimonial_slideshow',
      'label' => 'Testimonial Slideshow',
    ),
  );

 features_alter_code('eck_bundle', $items);

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

 features_alter_code('eck_entity_type', $items);

 return $items;
}

/**
 * Implements hook_image_default_styles().
 */
function imagex_splash_image_image_default_styles() {
  $styles = array();

  // Exported image style: feature_splash_mobile.
  $styles['feature_splash_mobile'] = array(
    'name' => 'feature_splash_mobile',
    'label' => 'Feature Splash Mobile',
    'effects' => array(
      20 => array(
        'label' => 'Manual Crop: Crop and scale',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 500,
          'height' => 300,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_mobile',
        ),
        'weight' => 0,
      ),
      21 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_narrow.
  $styles['feature_splash_narrow'] = array(
    'name' => 'feature_splash_narrow',
    'label' => 'Feature Splash Narrow',
    'effects' => array(
      18 => array(
        'label' => 'Manual Crop: Crop and scale',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 650,
          'height' => 600,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_narrow',
        ),
        'weight' => 0,
      ),
      19 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 650,
          'height' => 600,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_tablet.
  $styles['feature_splash_tablet'] = array(
    'name' => 'feature_splash_tablet',
    'label' => 'Feature Splash Tablet',
    'effects' => array(
      16 => array(
        'label' => 'Manual Crop: Crop and scale',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1000,
          'height' => 700,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_tablet',
        ),
        'weight' => 0,
      ),
      17 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 700,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_udesktop.
  $styles['feature_splash_udesktop'] = array(
    'name' => 'feature_splash_udesktop',
    'label' => 'Feature Splash Desktop',
    'effects' => array(
      14 => array(
        'label' => 'Manual Crop: Crop and scale',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1500,
          'height' => 700,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_udesktop',
        ),
        'weight' => 0,
      ),
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1500,
          'height' => 700,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_wide.
  $styles['feature_splash_wide'] = array(
    'name' => 'feature_splash_wide',
    'label' => 'Feature Splash Wide',
    'effects' => array(
      68 => array(
        'label' => 'Manual Crop: Crop and scale',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1170,
          'height' => 437,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_wide',
        ),
        'weight' => 0,
      ),
      69 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1170,
          'height' => 437,
        ),
        'weight' => 1,
      ),
    ),
  );

 features_alter_code('image', $styles);

 return $styles;
}
