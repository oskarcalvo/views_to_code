<?php

/**
 * @file
 * Default views.
 */

/**
 * Implements hook_views_default_views().
 */
function views_to_code_views_default_views() {

  $dir = DRUPAL_ROOT . '/' . drupal_get_path('module','views_to_code') . '/views';

  if (is_dir($dir)) {
    foreach (file_scan_directory($dir,'/\.inc$/') as $filepath => $file) {
    
      $resultado =  include $filepath;

      if (isset($view)) {  
        $views[$view->name] = $view;
      }
    }
  }
  return $views;
}
