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
    'username' => 'wiifm',
    'tweets_to_show' => 5,
  )
);


function layout_builder_regions_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['columns'] = array(
    '#title' => 'Columns',
    '#type' => 'textfield',
  );

  return $form;
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
  $block->content = 'qweqwe';

  return $block;
}
