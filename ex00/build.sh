#!/bin/sh

if !(cc -Wall -Wextra -Werror -o rush-01 *.c); then
	exit $?
fi

printf '%s' "Arguments: "
while IFS='\n' read -r arg; do
	./rush-01 "$arg"
	if [ -z "$arg" ]; then
		break
	fi
	printf '%s' "Arguments: "
done
