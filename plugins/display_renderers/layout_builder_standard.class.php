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
}