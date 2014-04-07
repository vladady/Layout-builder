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
  function render_pane_content(&$pane) {
    $current_display = &drupal_static('current_display');

    if(empty($current_display)) {
      $current_display = $this;
    }
    dpm($current_display);
    parent::render_pane_content($pane);
  }

  function ajax_add_pane($region = NULL, $type_name = NULL, $subtype_name = NULL, $step = NULL) {
      //dpm(func_get_args());
      parent::ajax_add_pane($region, $type_name, $subtype_name, $step);
  }

}
