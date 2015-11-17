<?php
/**
 * @file
 * parrot_splash_image.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function parrot_splash_image_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_bg|media_asset|splash|form';
  $field_group->group_name = 'group_video_bg';
  $field_group->entity_type = 'media_asset';
  $field_group->bundle = 'splash';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video Background',
    'weight' => '4',
    'children' => array(
      0 => 'field_video_bg_mp4',
      1 => 'field_video_bg_ogv',
      2 => 'field_video_bg_webm',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Video Background',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-video-bg field-group-fieldset',
        'description' => 'To provide best possible browser support it\'s recommended you upload videos for all the formats in the video fields below. If not upload is uploaded the "Background Image" image will be shown instead.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_video_bg|media_asset|splash|form'] = $field_group;

  return $export;
}
