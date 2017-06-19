<?php
/**
 * Created by PhpStorm.
 * User: oskar
 * Date: 16/06/17
 * Time: 16:48
 */

namespace Drupal\views_to_code\Helper;


class ViewsToCode {

  public $names;

  private $table = 'views_view';

  function __construct(array $names) {
    module_load_include('module', 'bulk_export', 'bulk_export.module');
    module_load_include('inc', 'ctools', 'includes/export.inc');

    $this->schema = ctools_export_get_schema($this->table);
    $files = [];
    foreach ($names as $name) {
      $files = $this->ctools_export_default_to_hook_code($this->schema,
        $this->tabe, $names, $this->name);
    }
  }

  /**
   * This function is a copy from ctools_export_default_to_hook_code
   * from the module ctools.
   * @param $schema
   * @param $table
   * @param $names
   * @param $name
   *
   * @return array
   */
  private function ctools_export_default_to_hook_code($schema, $table,$names) {
    $export = $schema['export'];
    $output = '';
    $objects = ctools_export_crud_load_multiple($table, $names);
    if ($objects) {

      $output = "<?php\n";
      $output .= "/**\n";
      $output .= " * Code exported by views to code module in date('Y-m-d') \n";
      $output .= " */\n";
      
      foreach ($objects as $object) {
        $output .= ctools_export_crud_export($table, $object, '  ');
      }
    }

    return ['name' => $names, 'code' => $output];
  }

}
/*
 * $schema = ctools_export_get_schema('views_view');
$table = 'views_view';
$names = ['providers_list_energy'];
$name = '' ;
$code = ctools_export_default_to_hook_code($schema, $table, $names, $name);
dpm($code);
 */