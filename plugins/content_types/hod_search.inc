<?php
/**
 *  Panel CTools create panel plugin
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('HoD Search'),
  'description' => t('HoD Search'),
  'category' => t('Straight North'),
  'render callback' => 'hod_custom_search',
  'admin info' => 'hod_search_listinfo',
  'defaults' => 'Test',
  );



/**
 *  Render Panel
 */
function hod_custom_search($subtype, $conf, $panel_args, $context = NULL) {

  // Yes, sloppy, I know
  if ($_REQUEST['category'] == 50) { $selected1 = 'SELECTED';}
  if ($_REQUEST['category'] == 36) { $selected2 = 'SELECTED';}
  if ($_REQUEST['category'] == 19) { $selected3 = 'SELECTED';}

  $content = '<form action="/search" method="GET">
                <ul class="header-search-list">
                <li class="txt"><input name="search_api_views_fulltext" class="form-text" type="text" value="' . $_REQUEST['search_api_views_fulltext'] . '" /></li>
                  <li class="sel"><select name="category">
                    <option value="all">All Products</option>
                    <option value="50" ' . $selected1 . '>House of Doolittle</option>
                    <option value="36" ' . $selected2 . '>Promotional</option>
                    <option value="19" ' . $selected3 . '>Collegiate</option>
                  </select></li>
                <li class="go"><input type="submit" value="Search" class="form-submit" /></li>
                <li class="close"><div id="header-search-close"></div></li>
                </ul>
              </form>';

  //dpm($_REQUEST);
  //$content = drupal_get_form('hod_search_custom_form');

  $display = $content;
  $block = new stdClass();
  $block->content = $display;
  return $block;

}


function hod_search_custom_form($form, &$form_state) {
  if ($_REQUEST['op'] == 'Search') {
    $searchvalue = $_REQUEST['search_api_views_fulltext'];
    $categoryvalue = $_REQUEST['category'];
  }
  $form['search_api_views_fulltext'] = array(
    '#type' => 'textfield',
    '#title' => t('Search'),
    '#default_value' => $searchvalue,
    '#maxlength' => 127,
  );
  $form['category'] = array(
    '#type' => 'select',
    '#title' => t('Category'),
    '#value' =>$categoryvalue,
    '#options' => array(
      'all' => 'All',
      50 => 'House of Doolittle',
      36 => 'Promotional',
      19 => 'Collegiate',
    ),
  );

 $form['submit'] = array(
   '#type' => 'submit',
   '#value' => 'Search'
 );
 return $form;
}

