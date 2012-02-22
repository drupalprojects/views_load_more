<?php

/**
 * The plugin to handle full pager.
 *
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_load_more extends views_plugin_pager_full {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'More pager, @count item, skip @skip', 'More pager, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
      return format_plural($this->options['items_per_page'], 'More pager, @count item', 'More pager, @count items', array('@count' => $this->options['items_per_page']));
  }

  function option_definition() {
    // @TODO: Add waypoint support.
    $options = parent::option_definition();
    $options['load_more_link_text'] = array(
      'default' => 'Load More',
      'translatable' => TRUE,
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['load_more_link_text'] = array(
      '#type' => 'textfield',
      '#weight' => -10,
      '#title' => t('"Load More" Link Text'),
      '#description' => t('The link title that will be used for the "Load More" anchor.'),
      '#default_value' => $this->options['load_more_link_text'],
    );
  }

  function render($input) {
    $pager_theme = views_theme_functions('views_load_more_pager', $this->view, $this->display);
    return theme($pager_theme, (empty($input) ? $this->options['load_more_link_text'] : $input), $this->options['items_per_page'], $this->options['id']);
  }
}

