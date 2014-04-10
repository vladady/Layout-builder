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
class layout_builder_standard extends panels_renderer_standard {
    function init($plugin, &$display) {
        dpm('x');

        parent::init($plugin, $display);
    }
    //@TODO - add 
    function render_panes() {
      dpm($this);
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
}