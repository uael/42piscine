#!/bin/sh
mkdir -p .obj
for src in *.c; do gcc -Wall -Wextra -Werror -c ${src} -o .obj/${src%.c}.o; done
ar rcs libft.a .obj/*.o
