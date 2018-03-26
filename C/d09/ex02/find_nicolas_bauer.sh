#!/bin/sh
cat contacts_easy.txt | grep -Ei "^(nicolas|bauer)" | grep -i "nicolas" | grep -i "bauer" | cut -c14- | cut -c-13 | \
    tr -d '\t' | tr -d ' ' | grep '\(([0-9]\{3\})\|[0-9]\{3\}\)[ -]\?[0-9]\{3\}[ -]\?[0-9]\{4\}'
