<?php

/**
 * Class Jaime
 */
class Jaime extends Lannister {

  public function sleepWith($who) {
    if (get_class($who) == "Cersei")
      echo "With pleasure, but only in a tower in Winterfell, then.".PHP_EOL;
		else if (get_parent_class($who) == "Lannister")
		  echo "Not even if I'm drunk !".PHP_EOL;
    else
      echo "Let's do this.".PHP_EOL;
	}
}
