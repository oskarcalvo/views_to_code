<?php

/**
 * @file form to export selected views
 */

/**
 * @param $form
 * @param $form_state
 */
function views_to_code_export_views($form, $form_state) {

  $query = db_select('views_view', 'v');
  $query->fields('v',array('name','human_name'));

  $result = $query->execute();
  foreach($result as $record) {
    $views[$record->name]  = $record->human_name;
  }
  asort($views);

  $form['list_of_views'] = [
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc($views),
    '#title' => t('Choose the views you want to export to code'),
  ];

  return $form;
}