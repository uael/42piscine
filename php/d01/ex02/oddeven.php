#!/usr/bin/php
<?php
while (true) {
  if (feof(STDIN))
    break;
  echo "Entrez un nombre: ";
  if (!($line = fgets(STDIN)))
    break;
  $line = trim($line);
  if (is_numeric($line))
    echo "Le chiffre $line est ".(($line % 2) == 0 ? "Pair" : "Impair");
  else
    echo "'$line' n'est pas un chiffre";
  echo PHP_EOL;
}
echo PHP_EOL;
