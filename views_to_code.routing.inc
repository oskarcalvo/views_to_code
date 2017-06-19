<?php

/**
 * @file routing file
 */

/**
 * Implements hook_menu().
 */
function views_to_code_menu() {

  $menu = [];

  $menu['admin/structure/views/viewsto_to_code'] = [
    'title'            => t('Selectra asset'),
    'description'      => t('Configure selectra external asset resources'),
    'page callback'    => 'drupal_get_form',
    'page arguments'   => ['vies_to_code_export_views'],
    'access arguments' => ['administer site configuration'],
    'type'             => MENU_NORMAL_ITEM,
    'file'             => 'src/Form/views_to_code_export_views.admin.inc',
  ];

  return $menu;
}