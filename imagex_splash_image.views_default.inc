<?php
/**
 * @file
 * imagex_splash_image.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function imagex_splash_image_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_asset_splash';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_media_asset';
  $view->human_name = 'Media Asset Splash';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_splash_node']['id'] = 'reverse_field_splash_node';
  $handler->display->display_options['relationships']['reverse_field_splash_node']['table'] = 'eck_media_asset';
  $handler->display->display_options['relationships']['reverse_field_splash_node']['field'] = 'reverse_field_splash_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_splash_target_id']['id'] = 'field_splash_target_id';
  $handler->display->display_options['relationships']['field_splash_target_id']['table'] = 'field_data_field_splash';
  $handler->display->display_options['relationships']['field_splash_target_id']['field'] = 'field_splash_target_id';
  $handler->display->display_options['relationships']['field_splash_target_id']['relationship'] = 'reverse_field_splash_node';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'flexslider_full',
    'image_link' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_body']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slide-content"><div class="slide-text">[field_body]</div></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_splash_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Splash Banner Pane */
  $handler = $view->new_display('panel_pane', 'Splash Banner Pane', 'panel_pane_1');
  $handler->display->display_options['pane_title'] = 'Splash Banner Pane';
  $handler->display->display_options['pane_category']['name'] = 'Media Elements';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Splash Banner Block */
  $handler = $view->new_display('block', 'Splash Banner Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'flexslider_1200x350',
    'image_link' => '',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_body']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slide-content"><div class="slide-text">[field_body]</div></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Splash Banner Block';

  /* Display: Block: Undergraduate Admissions */
  $handler = $view->new_display('block', 'Block: Undergraduate Admissions', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'undergraduate_admissions';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Thumbnail */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_image_1']['ui_name'] = 'Thumbnail';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_1']['alter']['text'] = '<div class="hidden-thumbnail-trojan" style="display: none;">[field_image_1]</div>';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'flexslider_172x144',
    'image_link' => '',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_splash_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'flexslider_588x290',
    'image_link' => '',
  );

  /* Display: Homepage Splash Banner Block */
  $handler = $view->new_display('block', 'Homepage Splash Banner Block', 'block_3');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['block_description'] = 'Homepage Splash Banner Block';
  $export['media_asset_splash'] = $view;

  return $export;
}
