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
  'regions' => array('middle' => t('Middle column')),
);
