<?php

/**
 * @file
 *   Includes a class that extends the Flag module for Statuses.
 */

/**
 * Make sure the flag_flag class is loaded before we extend it.
 * It won't be loaded yet if the Flag module hasn't loaded yet, because Flag
 * doesn't provide the kind of fancy autoloading that Views does.
 */
if (!class_exists('flag_flag')) {
  module_load_include('inc', 'flag');
}

/**
 * Adds a new flag type.
 */
class fbss_flag extends flag_flag {
  function _load_content($content_id) {
    return is_numeric($content_id) ? statuses_load($content_id) : NULL;
  }
  function applies_to_content_object($status) {
    return !empty($status) && isset($status->sid);
  }
  function get_content_id($status) {
    return $status->sid;
  }
  function get_labels_token_types() {
    return array_merge(array('statuses'), parent::get_labels_token_types());
  }
  function get_views_info() {
    return array(
      'views table' => 'statuses',
      'join field' => 'sid',
      'title field' => 'message',
      'title' => t('Statuses'),
      'help' => t('Display information about the flag set on a status.'),
      'counter title' => t('Statuses flag counter'),
      'counter help' => t('Include this to gain access to the flag counter field.'),
    );
  }
  function applies_to_content_id_array($content_ids) {
    foreach ($content_ids as $content_id) {
      $passed[$content_id] = TRUE;
    }
    return $passed;
  }
  function get_relevant_action_objects($content_id) {
    return array(
      'statuses' => $this->fetch_content($content_id),
    );
  }
  function replace_tokens($label, $contexts, $options, $content_id) {
    if ($content_id && ($status = $this->fetch_content($content_id))) {
      $contexts['statuses'] = $status;
    }
    return parent::replace_tokens($label, $contexts, $options, $content_id);
  }
  function get_flag_action($content_id) {
    $flag_action = parent::get_flag_action($content_id);
    $status = $this->fetch_content($content_id);
    $flag_action->content_title = $status->message;
    $context = statuses_determine_context($status->type);
    $flag_action->content_url = $context['handler']->recipient_url($context['handler']->load_recipient($status->recipient));
    return $flag_action;
  }
  function rules_get_event_arguments_definition() {
    return array(
      'account' => array(
        'type' => 'statuses',
        'label' => t('Flagged status'),
        'handler' => 'flag_rules_get_event_argument',
      ),
    );
  }
  function rules_get_element_argument_definition() {
    return array('type' => 'statuses', 'label' => t('Flagged status'));
  }
}

/**
 * Adds a new flag type.
 */
class fbss_flag_three extends flag_flag {
  /**
   * Loads the entity object.
   */
  function _load_entity($entity_id) {
    return is_numeric($entity_id) ? statuses_load($entity_id) : NULL;
  }

  /**
   * Returns TRUE if the flag applies to the entity with the given ID.
   *
   * This is a convenience method that simply loads the object and calls
   * applies_to_entity(). If you already have the object, don't call
   * this function: call applies_to_entity() directly.
   */
  function applies_to_entity_id($entity_id) {
    return $this->applies_to_entity($this->fetch_entity($entity_id));
  }

  /**
   * Checks whether the flag applies for the current entity bundle.
   */
  function applies_to_entity($entity) {
    if ($entity) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Returns the entity id, if it already exists.
   */
  function get_entity_id($entity) {
    if ($entity && isset($entity->sid)) {
      return $entity->sid;
    }
  }

  /**
   * Returns TRUE if the link should be displayed.
   */
  function uses_hook_link($teaser) {
    return TRUE;
  }

  /**
   * Returns token types for the current entity type.
   */
  function get_labels_token_types() {
    return array_merge(array('statuses'), parent::get_labels_token_types());
  }

  /**
   * Returns information for the Views integration.
   */
  function get_views_info() {
    return array(
      'views table' => 'statuses',
      'join field' => 'sid',
      'title field' => 'message',
      'title' => t('Statuses'),
      'help' => t('Display information about the flag set on a status.'),
      'counter title' => t('Statuses flag counter'),
      'counter help' => t('Include this to gain access to the flag counter field.'),
    );
  }

  /**
   * Returns objects the action may possible need.
   */
  function get_relevant_action_objects($entity_id) {
    return array(
      'statuses' => $this->fetch_entity($entity_id),
    );
  }

  /**
   * Replaces tokens.
   */
  function replace_tokens($label, $contexts, $options, $entity_id) {
    if ($entity_id && ($entity = $this->fetch_entity($entity_id))) {
      $contexts['statuses'] = $entity;
    }
    return parent::replace_tokens($label, $contexts, $options, $entity_id);
  }

  /**
   * Returns a 'flag action' object.
   */
  function get_flag_action($entity_id) {
    $flag_action = parent::get_flag_action($entity_id);
    $status = $this->fetch_entity($entity_id);
    $flag_action->entity_title = $status->message;
    $context = statuses_determine_context($status->type);
    $flag_action->entity_url = $context['handler']->recipient_url($context['handler']->load_recipient($status->recipient));
    return $flag_action;
  }
}
