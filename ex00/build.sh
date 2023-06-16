#!/bin/sh

trap cleanup EXIT

function cleanup {
	printf '\n'
	printf 'Cleaning up...\n'
	[ -e rush-01 ] && rm rush-01
	printf 'Cleaning done.'
}

function main {
	printf 'Compiling the program...\n'
	if !(cc -Wall -Wextra -Werror -o rush-01 *.c); then
		exit $?
	fi
	printf 'Compilation done.\n'

	printf 'Test the program by typing the arguments, press Ctrl+C to exit.\n'
	printf 'Arguments: '
	while IFS='\n' read -r args; do
		echo ${args[@]} | xargs ./rush-01
		printf 'Arguments: '
	done
}

main

