<?php
/**
 * @file
 * humanitarianresponse_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function humanitarianresponse_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'On search view';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'search:page' => 'search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-Shb0Q1vWgCArrHrjHszTyhl2jaEhIjzW' => array(
          'module' => 'facetapi',
          'delta' => 'Shb0Q1vWgCArrHrjHszTyhl2jaEhIjzW',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'facetapi-Nars6CXEF2stEbUlZR8NEnqEtBDARTb1' => array(
          'module' => 'facetapi',
          'delta' => 'Nars6CXEF2stEbUlZR8NEnqEtBDARTb1',
          'region' => 'sidebar_second',
          'weight' => '-30',
        ),
        'facetapi-SRTVUTAsjHh8QrIHE2NMBl3MM1s3qOKp' => array(
          'module' => 'facetapi',
          'delta' => 'SRTVUTAsjHh8QrIHE2NMBl3MM1s3qOKp',
          'region' => 'sidebar_second',
          'weight' => '-25',
        ),
        'facetapi-cpoyWFNPOVLHvKGY6t6bb8LVM41Xs2Dm' => array(
          'module' => 'facetapi',
          'delta' => 'cpoyWFNPOVLHvKGY6t6bb8LVM41Xs2Dm',
          'region' => 'sidebar_second',
          'weight' => '-20',
        ),
        'facetapi-YQrWdaYB0Jm9BGw7VcgHFswJHlxawCsl' => array(
          'module' => 'facetapi',
          'delta' => 'YQrWdaYB0Jm9BGw7VcgHFswJHlxawCsl',
          'region' => 'sidebar_second',
          'weight' => '-15',
        ),
        'facetapi-WaEgyIn8f6HkMj1R536Y3vBptvKRj30W' => array(
          'module' => 'facetapi',
          'delta' => 'WaEgyIn8f6HkMj1R536Y3vBptvKRj30W',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-FKBVzvYt9xMqDr8L58X0KOiiv1D8E5Ao' => array(
          'module' => 'facetapi',
          'delta' => 'FKBVzvYt9xMqDr8L58X0KOiiv1D8E5Ao',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'facetapi-UrbbwTPM31dQGgHrSt9Tjdnblkw12f6E' => array(
          'module' => 'facetapi',
          'delta' => 'UrbbwTPM31dQGgHrSt9Tjdnblkw12f6E',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'facetapi-X58ryLY6CGnPf1gQI0rVOUGTHXHh4EfL' => array(
          'module' => 'facetapi',
          'delta' => 'X58ryLY6CGnPf1gQI0rVOUGTHXHh4EfL',
          'region' => 'sidebar_second',
          'weight' => '5',
        ),
        'facetapi-rOO3lO2B480jNa51cz03IJgosO6bbCBm' => array(
          'module' => 'facetapi',
          'delta' => 'rOO3lO2B480jNa51cz03IJgosO6bbCBm',
          'region' => 'sidebar_second',
          'weight' => '10',
        ),
        'facetapi-JAKZs3absS9kL1zrH6idqbCFj61Z4SpL' => array(
          'module' => 'facetapi',
          'delta' => 'JAKZs3absS9kL1zrH6idqbCFj61Z4SpL',
          'region' => 'sidebar_second',
          'weight' => '15',
        ),
        'facetapi-Uz43FkEp5BeMap09k2L4q5cxiMpioh2N' => array(
          'module' => 'facetapi',
          'delta' => 'Uz43FkEp5BeMap09k2L4q5cxiMpioh2N',
          'region' => 'sidebar_second',
          'weight' => '25',
        ),
      ),
    ),
    'breadcrumb' => '<front>',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('On search view');
  t('search');
  $export['search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_box';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search-page' => array(
          'module' => 'views',
          'delta' => '-exp-search-page',
          'region' => 'user_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['search_box'] = $context;

  return $export;
}