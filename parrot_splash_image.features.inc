<?php
/**
 * @file
 * parrot_splash_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function parrot_splash_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function parrot_splash_image_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function parrot_splash_image_eck_bundle_info() {
  $items = array(
    'media_asset_carousel' => array(
      'machine_name' => 'media_asset_carousel',
      'entity_type' => 'media_asset',
      'name' => 'carousel',
      'label' => 'Carousel',
      'config' => array(),
    ),
    'media_asset_carousel_item' => array(
      'machine_name' => 'media_asset_carousel_item',
      'entity_type' => 'media_asset',
      'name' => 'carousel_item',
      'label' => 'Carousel Item',
      'config' => array(),
    ),
    'media_asset_slideshow' => array(
      'machine_name' => 'media_asset_slideshow',
      'entity_type' => 'media_asset',
      'name' => 'slideshow',
      'label' => 'Slideshow',
      'config' => array(),
    ),
    'media_asset_splash' => array(
      'machine_name' => 'media_asset_splash',
      'entity_type' => 'media_asset',
      'name' => 'splash',
      'label' => 'Splash',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function parrot_splash_image_eck_entity_type_info() {
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
function parrot_splash_image_image_default_styles() {
  $styles = array();

  // Exported image style: feature_splash_mobile.
  $styles['feature_splash_mobile'] = array(
    'label' => 'Feature Splash Mobile',
    'effects' => array(
      71 => array(
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
      76 => array(
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
    'label' => 'Feature Splash Narrow',
    'effects' => array(
      61 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 600,
          'height' => 400,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_narrow',
        ),
        'weight' => 0,
      ),
      66 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 400,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_tablet.
  $styles['feature_splash_tablet'] = array(
    'label' => 'Feature Splash Tablet',
    'effects' => array(
      51 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 800,
          'height' => 320,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_tablet',
        ),
        'weight' => 0,
      ),
      56 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 320,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_udesktop.
  $styles['feature_splash_udesktop'] = array(
    'label' => 'Feature Splash Desktop',
    'effects' => array(
      41 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1100,
          'height' => 440,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_udesktop',
        ),
        'weight' => 0,
      ),
      46 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1100,
          'height' => 440,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_splash_wide.
  $styles['feature_splash_wide'] = array(
    'label' => 'Feature Splash Wide',
    'effects' => array(
      31 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1440,
          'height' => 575,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'feature_splash_wide',
        ),
        'weight' => 0,
      ),
      36 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1440,
          'height' => 575,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
