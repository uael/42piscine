<?php

class UnholyFactory {
  private $_abso;

  public function __construct() {
    $this->_abso = array();
  }

  public function absorb($fighter) {
    if (get_parent_class($fighter) == "Fighter") {
      if (!in_array($fighter->get_type(), $this->get_abso())) {
        echo "(Factory absorbed a fighter of type " . $fighter->get_type() . ")" . PHP_EOL;
        $this->_set_abso($fighter->get_type());
      } else
        echo "(Factory already absorbed a fighter of type " . $fighter->get_type() . ")" . PHP_EOL;
    } else
      echo "(Factory can't absorb this, it's not a fighter)" . PHP_EOL;
  }

  public function fabricate($rf) {
    switch ($rf) {
      case "foot soldier":
        $f = New Footsoldier();
        break;
      case "archer":
        $f = New Archer();
        break;
      case "assassin":
        $f = New Assassin();
        break;
      default :
        $f = null;
    }
    if ($f != null)
      echo "(Factory fabricates a fighter of type " . $rf . ")" . PHP_EOL;
    else
      echo "(Factory hasn't absorbed any fighter of type " . $rf . ")" . PHP_EOL;
    return ($f);
  }

  private function get_abso() {
    return $this->_abso;
  }

  private function _set_abso($who) {
    array_push($this->_abso, $who);
  }
}
