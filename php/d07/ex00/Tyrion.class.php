<?php

/**
 * Class Tyrion
 */
class Tyrion extends Lannister {

  public function __construct() {
    parent::__construct();
    echo "My name is ".$this.PHP_EOL;
  }

  public function __toString() {
    return "Tyrion";
  }

  public function getSize() {
    return "Short";
  }
}
