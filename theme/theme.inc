<?php

  /**
   * @file Theming functionality
   * @author griffinj@lafayette.edu
   *
   */

function islandora_dss_large_image_preprocess_islandora_large_image(array &$variables) {

  $islandora_object = $variables['islandora_object'];

  global $base_url;
  $meta_ie_render_engine = array('#type' => 'html_tag',
				 '#tag' => 'meta',
				 '#attributes' => array('property' =>  'og:image',
							'content' => $base_url . '/' . current_path() . '/datastream/JPG/view',
							)
				 );
 
  // Add header meta tag for IE to head
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');
}
