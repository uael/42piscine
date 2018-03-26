#/bin/sh
ldapsearch -LLL -Q "uid=z*" uid cn | grep "^cn: .*" | sed 's/cn: //' | sort -r -f

