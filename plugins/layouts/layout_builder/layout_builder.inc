<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Layout builder'),
  'category' => t('Layout builder'),
  //'icon' => 'onecol.png',
  'theme' => 'panels_layout_builder',
  'css' => 'panels_layout_builder.css',
  'regions function' => 'layout_builder_regions',
);

function layout_builder_regions($display, $settings, $layout) {
   //@TODO - make real regions

   $cache = cache_get($display->cache_key);
   
   $regions = array();

   if(isset($cache->data)) {
     foreach ($cache->data as $region_id) {
       $regions[$region_id] = $region_id;
     }
   }

   $default = array(
       'region1' => t('Region1'),
       //'region2' => t('Region2'),
   );
   
   $regions += $default;
   //dpm($regions);
   return $regions;
}