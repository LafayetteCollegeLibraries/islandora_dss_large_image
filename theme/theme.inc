<?php

  /**
   * @file Theming functionality
   * @author griffinj@lafayette.edu
   *
   */

function islandora_dss_large_image_process_islandora_large_image(array &$variables) {

  $islandora_object = $variables['islandora_object'];

  global $base_url;
  $meta_element_open_graph_type = array('#type' => 'html_tag',
					'#tag' => 'meta',
					'#attributes' => array('property' =>  'og:type',
							       'content' => 'article'),
					);

  $meta_element_open_graph_url = array('#type' => 'html_tag',
				       '#tag' => 'meta',
				       '#attributes' => array('property' =>  'og:url',
							      'content' => $base_url . '/' . drupal_get_path_alias()),
				       );

  $meta_element_open_graph_author = array('#type' => 'html_tag',
					  '#tag' => 'meta',
					  '#attributes' => array('property' =>  'og:author',
								 'content' => 'https://www.facebook.com/LafayetteCollegeLibrary',
								 )
					  );
  $meta_element_open_graph_title = array('#type' => 'html_tag',
					 '#tag' => 'meta',
					 '#attributes' => array('property' =>  'og:title',
								'content' => $islandora_object->label,
								)
					 );
  // For all <meta> elements
  $meta_elements = array(
			 'meta_element_open_graph_type' => $meta_element_open_graph_type,
			 'meta_element_open_graph_url' => $meta_element_open_graph_url,
			 'meta_element_open_graph_author' => $meta_element_open_graph_author,
			 'meta_element_open_graph_title' => $meta_element_open_graph_title,
			 );
  $meta_elements['meta_element_open_graph_image'] = array('#type' => 'html_tag',
							  '#tag' => 'meta',
							  '#attributes' => array('property' =>  'og:image',
										 'content' => $base_url . '/' . current_path() . '/datastream/JPG/view',
										 ),
				
							  );

  foreach($variables['mods_object'] as $mods_element) {

    if(array_key_exists('facet', $mods_element) and $mods_element['facet'] == 'cdm.Relation.IsPartOf') {

      $collection = $mods_element['value'];
    }
  }

  $meta_elements['meta_element_open_graph_description'] = array('#type' => 'html_tag',
								'#tag' => 'meta',
								'#attributes' => array('property' =>  'og:description',
										       'content' => $collection,
										       )
								);
  $meta_elements['meta_element_open_graph_site_name'] = array('#type' => 'html_tag',
							      '#tag' => 'meta',
							      '#attributes' => array('property' =>  'og:site_name',
										     'content' => 'Digital Scholarship Services',
										     )
							      );

  foreach($meta_elements as $key => $meta_element) {

    // Add header meta tag for IE to head
    drupal_add_html_head($meta_element, $key);
  }
  }
