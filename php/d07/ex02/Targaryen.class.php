<?php

/**
 * Class Targaryen
 */
class Targaryen {

	public function resistsFire() {
		return false;
	}

	public function getBurned() {
		return static::resistsFire() ? 
			"emerges naked but unharmed" : "burns alive";
	}
}
