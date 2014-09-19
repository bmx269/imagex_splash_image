<?php
/**
 * @file
 * parrot_splash_image.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function parrot_splash_image_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-media_asset_splash-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'media_asset_splash-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admissions/undergraduate-admissions',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'felician' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'felician',
        'weight' => -11,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-media_asset_splash-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'media_asset_splash-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admissions/undergraduate-admissions',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'felician' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'felician',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
