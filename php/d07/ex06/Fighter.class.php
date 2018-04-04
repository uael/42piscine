<?php

abstract class Fighter {
  private $_type;

  public function __construct($arg) {
    $this->set_type($arg);
  }

  public function get_type() {
    return $this->_type;
  }

  public function set_type($type) {
    $this->_type = $type;
  }

  abstract public function fight($target);
}
