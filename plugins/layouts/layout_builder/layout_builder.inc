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
  'regions' => array(
    'region1' => t('Region1'),
    'region2' => t('Region2'),
  ),
);
