<?php
// $Id$
/**
 * @file
 *
 * Handle all block related data
 *
 */

/**
 * Display block content
 * @return content for the block
 */
function asc_sql_migration_main() {
  // content variable that will be returned for display
  $content = '';
  
  // Content
  $content .= '<h1>ASC SQL Migration Checks</h1>';
  $content .= asc_sql_migration_run_queries();
  
  // return our content
  return $content;
} // function asc_sql_migration_main()

function asc_sql_migration_run_queries() {
  
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $prod_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_server_root", 'drupal.asc.ohio-state.edu'));
  $dev_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_server_root", 'drupal-d.asc.ohio-state.edu'));
  $prod_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_sym_link_ext", '-s.asc.ohio-state.edu'));
  $dev_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_sym_link_ext", '-d.asc.ohio-state.edu'));
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));

  $content .= asc_sql_migration_block_files_qry_1();  
  $content .= asc_sql_migration_block_files_qry_2();
  $content .= asc_sql_migration_block_body_qry_1();
  $content .= asc_sql_migration_block_body_qry_2();
  $content .= asc_sql_migration_block_body_qry_3();
  $content .= asc_sql_migration_block_body_qry_4();
  $content .= asc_sql_migration_block_body_qry_5();
  $content .= asc_sql_migration_node_files_qry_1();
  $content .= asc_sql_migration_node_files_qry_2();
  $content .= asc_sql_migration_node_body_qry_1();
  $content .= asc_sql_migration_node_body_qry_2();
  $content .= asc_sql_migration_node_body_qry_3();
  $content .= asc_sql_migration_node_body_qry_4();
  $content .= asc_sql_migration_node_body_qry_5();

  // Provide a way to refresh queries
  $content .= '<a href="javascript:history.go(0)" title="Refresh all queries.">Refresh Queries</a>';
  
  // Return our content
  return $content;
}

function asc_sql_migration_clean_string($string) {
  $string = filter_xss($string);
  $string = check_plain($string);
  return $string;
}

function asc_sql_migration_block_files_qry_1() {  
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));

  // Prepare the string to be searched for
  $qry_string = $site_name . "/files/" . $site_name;
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
   
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_files_qry_2() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));

  // Prepare the string to be searched for
  $qry_string = $site_name . "/%' AND body NOT LIKE '%/files/" . $site_name . "/";
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
    
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_body_qry_1() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $prod_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_server_root", 'drupal.asc.ohio-state.edu')); 
  
  // Prepare the string to be searched for
  $qry_string = $prod_server_root;
  
   // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_body_qry_2() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $dev_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_server_root", 'drupal-d.asc.ohio-state.edu'));
  
  // Prepare the string to be searched for
  $qry_string = $dev_server_root;
  
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_body_qry_3() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . ".osu.edu";
  
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_body_qry_4() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $dev_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_sym_link_ext", '-d.asc.ohio-state.edu'));
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . $dev_sym_link_ext;
  
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_block_body_qry_5() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $prod_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_sym_link_ext", '-s.asc.ohio-state.edu'));
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . $prod_sym_link_ext;
  
  // Prepare the SQL
  $qry = 'SELECT bid, body FROM boxes WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_files_qry_1() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . "/files/" . $site_name;
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_files_qry_2() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . "/%' AND body NOT LIKE '%/files/" . $site_name . "/";
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_body_qry_1() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $prod_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_server_root", 'drupal.asc.ohio-state.edu'));
  
  // Prepare the string to be searched for
  $qry_string = $prod_server_root;
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_body_qry_2() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $dev_server_root = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_server_root", 'drupal-d.asc.ohio-state.edu'));
  
  // Prepare the string to be searched for
  $qry_string = $dev_server_root;
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_body_qry_3() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));

  // Prepare the string to be searched for
  $qry_string = $site_name . ".osu.edu";
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_body_qry_4() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $dev_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_dev_sym_link_ext", '-d.asc.ohio-state.edu'));
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . $dev_sym_link_ext;
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_node_body_qry_5() {
  // Initialize the content variable
  $content = '';
  
  // Import variables
  $prod_sym_link_ext = asc_sql_migration_clean_string(variable_get("asc_sql_migration_prod_sym_link_ext", '-s.asc.ohio-state.edu'));
  $site_name = asc_sql_migration_clean_string(variable_get("asc_sql_migration_site_name", 'asctech'));
  
  // Prepare the string to be searched for
  $qry_string = $site_name . $prod_sym_link_ext;
  
  // Prepare the SQL
  $qry = 'SELECT nid, body, teaser FROM node_revisions WHERE body LIKE "%%%s%"';
  
  // Run the query and return the results
  $content .= asc_sql_migration_run_query($qry, $qry_string);
  
  // Return our content
  return $content;
}

function asc_sql_migration_run_query($qry, $qry_string) {
  // Initialize the content variable
  $content = '';
  
  // Run the query and store the results
  $qry_result = db_query($qry, $qry_string);
  
  // Provide a message describing the potential problem
  $content .= 'The following blocks contain the text "<em>' . $qry_string . '</em>", which could be an issue.<br />';
  
  // Start the list of links
  $content .= '<ul>';  
  // Loop over our results
  while ($row = db_fetch_object($qry_result)) {
    // Link to our potential problem node or block
    $content .= '<li><a href="/admin/build/block/configure/block/' . $row->bid . '" title="Go to the page to edit block ' . $row->bid . '">Edit block ' . $row->bid . '</a></li>';
  }
  // End the list of links
  $content .= '</ul>';
  
  // Return our content
  return $content;
}