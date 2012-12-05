<?php

/**
 * Admin menu page for the basic settings
 */
function pp_hessen_admin_form() {
  $form = array();


  $form['wiki_url'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wiki-Einstellungen'),
    '#description' => t('Die Zahlen der Mitgliedsdaten werden aus dem Wiki geholt und dargestellt.'),
  );

  $form['wiki_url']['pp_hessen_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL (z.B. wiki.piratenpartei.de)'),
    '#default_value' => variable_get('pp_hessen_url', NULL),
  );

  $form['wiki_url']['pp_hessen_site'] = array(
    '#type' => 'textfield',
    '#title' => t('Seite (z.B. HE:Landkreise/Mitgliederzahlen)'),
    '#default_value' => variable_get('pp_hessen_site', NULL),
  );


  $form['stats'] = array(
    '#type' => 'fieldset',
    '#title' => t('Statistik'),
    '#description' => t('Daten des letzten Laufes.'),
  );

  $form['stats']['count'] = array(
    '#type' => 'item',
    '#title' => t('Piraten'),
    '#description' => variable_get('pp_hessen_count', NULL),
  );

  $form['stats']['last_run'] = array(
    '#type' => 'item',
    '#title' => t('Datum'),
    '#description' => date("d.m.Y H:i:s", variable_get('pp_hessen_last_run', NULL)),
  );

  $form['stats']['checksum'] = array(
    '#type' => 'item',
    '#title' => t('Checksum'),
    '#description' => variable_get('pp_hessen_checksum', NULL)."<br />(<a href='/admin/settings/piraten/hessen/reset'>Reset</a>)",
  );


  return system_settings_form($form);
}
