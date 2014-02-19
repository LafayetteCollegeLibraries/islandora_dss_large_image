<?php

/**
 * @file
 * This is the template file for the object page for large image
 *
 * Available variables:
 * - $islandora_object: The Islandora object rendered in this template file
 * - $islandora_dublin_core: The DC datastream object
 * - $dc_array: The DC datastream object values as a sanitized array. This
 *   includes label, value and class name.
 * - $islandora_object_label: The sanitized object label.
 * - $parent_collections: An array containing parent collection(s) info.
 *   Includes collection object, label, url and rendered link.
 * - $islandora_thumbnail_img: A rendered thumbnail image.
 * - $islandora_content: A rendered image. By default this is the JPG datastream
 *   which is a medium sized image. Alternatively this could be a rendered
 *   viewer which displays the JP2 datastream image.
 *
 * @see template_preprocess_islandora_large_image()
 * @see theme_islandora_large_image()
 */
?>

<div class="islandora-large-image-object islandora">
  <div class="islandora-large-image-content-wrapper clearfix">
    <?php if ($islandora_content): ?>
      <div class="islandora-large-image-content">
        <?php print $islandora_content; ?>
      </div>
    <?php endif; ?>
  </div>
  <fieldset class="collapsible collapsed islandora-large-image-metadata">
  <h3 class="islandora-image-details">Details</h3>
    <div class="fieldset-wrapper">
      <dl class="islandora-inline-metadata islandora-large-image-fields">
        <?php $row_field = 0; ?>

        <?php if (isset($mods_object)): ?>

          <?php foreach ($mods_object as $key => $value): ?>

            <dt class="<?php
print $value['class'];
print $row_field == 0 ? ' first' : '';
if($value['label'] != ''):

  print ' islandora-inline-metadata-displayed';
endif;
?>">

              <?php print $value['label']; ?>
            </dt>
            <dd class="<?php print $value['class']; ?><?php print $row_field == 0 ? ' first' : ''; ?>">

              <?php if(array_key_exists('date_value', $value)): ?>

	        <?php print array_key_exists('facet', $value) ? l($value['date_value'], "islandora/search/*:*", array('query' => array('f[0]' => $value['facet'] . ':' . $value['facet_value'] . ''
																       ))) : $value['date_value']; ?>
	      <?php else: ?>

                <?php

		    // print array_key_exists('facet', $value) ? l($value['value'], "islandora/search/eastasia." . $value['facet'] . "%3A" . $value['facet_value']) : $value['value'];
		    if(array_key_exists('facet', $value)) {

		      //print l($value['value'], "islandora/search/*:*?f[0]=" . $value['facet'] . ':' . $value['facet_value'] . '');
		      print l($value['value'], "islandora/search/*:*", array('query' => array('f[0]' => $value['facet'] . ':' . $value['facet_value'] . '')));
		    } elseif(array_key_exists('href', $value)) {

                      print l($value['value'], $value['href']);
		    } else {

		      print $value['value'];
		    }
		?>
	      <?php endif; ?>
            </dd>
          <?php $row_field++; ?>
        <?php endforeach; ?>
        <?php endif; ?>
      </dl>
    </div>
  </fieldset>
</div>
