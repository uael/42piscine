<?php

/**
 * Class NightsWatch
 */
class NightsWatch {
  private $_crew;

  public function __construct() {
    $this->_crew = [];
  }

  public function recruit($who) {
    $this->_set_crew($who);
  }

  public function fight() {
    $crew = $this->get_crew();
    foreach ($crew as $somebody)
      if (array_key_exists("IFighter", class_implements($somebody)))
        $somebody->fight();
  }

  private function get_crew() {
    return $this->_crew;
  }

  private function _set_crew($who) {
    array_push($this->_crew, $who);
  }
}
