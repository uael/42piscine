<?php

/**
 * Class Lannister
 */
class Lannister {
	public function sleepWith($who) {
		if (get_parent_class($who) == "Lannister")
			echo "Not even if I'm drunk !".PHP_EOL;
		else
			echo "Let's do this.".PHP_EOL;
	}
}
