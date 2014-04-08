<?php
/**
 * @file
 * Contains the simple display renderer.
 */

/**
 * The simple display renderer renders a display normally, except each pane
 * is already rendered content, rather than a pane containing CTools content
 * to be rendered. Styles are not supported.
 */

/*
  panels_renderer_standard
  panels_renderer_editor
  panels_renderer_ipe
*/
class layout_builder_editor extends panels_renderer_ipe {
/*  function render_regions() {
    $this->rendered['regions'] = array();
    foreach ($this->display->content as $region_id => $content) {
      if (is_array($content)) {
        $content = implode('', $content);
      }

      $this->rendered['regions'][$region_id] = $content;
    }
    return $this->rendered['regions'];
  }

  function render_panes() {
    //return parent::render_panes()
  }

  function prepare($external_settings = NULL) {
    $this->prep_run = TRUE;
  }*/

  function ajax_save_form($break = NULL) {
    $current_display = &drupal_static('current_display');
    if(empty($current_display)) {
        $current_display = $this;
    }

    parent::ajax_save_form($break);
  }
  function render_panes() {
    ctools_include('content');

    // First, render all the panes into little boxes.
    $this->rendered['panes'] = array();

    // TODO - make sorting of panes according to nesting
    $this->prepared['panes'] = array_reverse($this->prepared['panes'], true);

    foreach ($this->prepared['panes'] as $pid => $pane) {
      $content = $this->render_pane($pane);
      if ($content) {
        $this->rendered['panes'][$pid] = $content;
      }
    }
    return $this->rendered['panes'];
  }
  
  function command_add_pane($pid) {
    if (is_object($pid)) {
      $pane = $pid;
    }
    else {
      $pane = $this->display->content[$pid];
    }

    $this->commands[] = array(
      'command' => 'insertNewPane',
      'regionId' => $pane->panel,
      'renderedPane' => $this->render_pane($pane),
    );
    $this->commands[] = ajax_command_changed("#panels-ipe-display-{$this->clean_key}");
    
    //Added paneId to create sort region
    $this->commands[] = array(
      'command' => 'addNewPane',
      'paneId' => $pane->pid,
      'key' => $this->clean_key,
    );
  }

  function ajax_add_pane($region = NULL, $type_name = NULL, $subtype_name = NULL, $step = NULL) {
      //Prepare in case of special panes
      if($type_name == 'layout_builder_regions') {
          $this->prepare();
      }
      
      $current_display = &drupal_static('current_display');
      if(empty($current_display)) {
          $current_display = $this;
      }

      parent::ajax_add_pane($region, $type_name, $subtype_name, $step);
  }
  
  //@TODO - Save command cache static current display
}
