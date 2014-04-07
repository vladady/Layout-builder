<?php

$plugin = array(
  //'single' => TRUE,
  'title' => t('Layout builder regions'),
  'description' => t('Adds regions.'),
  'category' => t('Layout builder'),
  'edit form' => 'layout_builder_regions_edit_form',
  'render callback' => 'layout_builder_regions_render',
  'admin info' => 'layout_builder_regions_admin_info',
  'defaults' => array(
    'cols' => 2,
  )
);


function layout_builder_regions_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['columns'] = array(
    '#title' => 'Columns',
    '#type' => 'textfield',
    '#default_value' => $conf['cols'],
    '#size' => 1,
  );

  return $form;
}

function layout_builder_regions_edit_form_submit($form, &$form_state) {
  $next_id = 0;
  $display = $form_state['display'];

  foreach($display->panels as $region_id => $pids) {
    $id = str_replace('region', '', $region_id);
    if($id >= $next_id) {
      $next_id = $id + 1;
    }
  }
  $next_id = 2;
  $cols = isset($form_state['values']['columns']) ? $form_state['values']['columns'] : 2;
  
  $form_state['conf']['cols'] = $cols;
  for ($i = 0; $i < $cols; $i++) {
    $form_state['conf']['regions'][] = 'region' . $next_id++;
  }
  
  cache_set($display->cache_key, $form_state['conf']['regions']);
  //dpm($next_id);
}

function layout_builder_regions_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

    $block->content = 'sadasdas';

    return $block;
  }
}

function layout_builder_regions_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // initial content is blank
  $block->title = '';
  $block->content = array();
  
  //dpm(func_get_args());
  $display = panels_get_current_page_display();
  dpm(debug_backtrace());
  if(!$display) {
    $current_display = &drupal_static('current_display');
    $handler = $current_display;
    //$handler->ren
    //$handler = new layout_builder_editor();
  }
  else {
    $handler = $display->renderer_handler;
  }

  dpm($handler);

  $i = 0;

  $block->content['#prefix'] = '<div>' . rand(100, 1);
  $block->content['#suffix'] = '</div>';
  //foreach($handler->prepared['regions'] as $region_id => $conf) {

  foreach($conf['regions'] as $region_id) {
     //dpm($region_id);
     $region = $handler->render_region($region_id, array());
     //$region = '';
     $block->content[$region_id] = $region;
  }


  return $block;
  
  foreach($inner_regions as $region_id) {
    $region_panes = array();
    dpm($region_id);

    foreach ($handler->prepared['regions'][$region_id]['pids'] as $pid) {
      $region_panes[$pid] = $handler->rendered['panes'][$pid];
    }

    $block->content[$region_id] = array(
        '#markup' => $handler->render_region($region_id, $region_panes),
    );
  }


  
//  $block->content['region2'] = array(
//      '#markup' => $handler->render_region('region2', array()),
//      '#weight' => $i,
//      '#prefix' => '<div style="width:49%;padding:3px;float:left">',
//      '#suffix' => '</div>',
//  );
   dpm($block);
  //}

  //$block->content = $handler->render_region('region2', array());
  return $block;
}
