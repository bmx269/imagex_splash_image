<?php
// Slide wrapper
// @see field "Slide Content" in media_asset_splash view

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$splash_id = $row->eck_media_asset_field_data_field_splash_id;
$videos = array();
$classes = '';
foreach (array('mp4', 'ogv', 'webm') as $format) {
  $field_key = 'field_field_video_bg_' . $format;
  if (!empty($row->{$field_key})) {
    $video_url = render($row->{$field_key}[0]['rendered']);
    $videos[] = '<source src="' . $video_url . '" type="video/' . $format . '">';
    $classes = ' slide-has-video';
  }
}
$poster = '';
if (!empty($row->field_field_image)) {
  //$poster = ' poster="' . render($row->field_field_image[0]['rendered']) . '"';
}

$attr = '';
if (!empty($row->field_field_height)) {
  $attr = ' data-ideal-height=' . render($row->field_field_height[0]['rendered']);
}
?>
<div class="slide media-id-<?php echo $splash_id; ?><?php echo $classes; ?>"<?php echo $attr; ?>>
  <?php if (!empty($videos)) { ?>
  <video class="slide-video"<?php echo $poster; ?> preload="auto">
    <?php echo implode('', $videos); ?>
  </video>
  <?php }; ?>
  <div class="slide-content">
    <div class="slide-text">  
    <?php print $output; ?>
    </div>
  </div>
</div>

