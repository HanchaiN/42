#!/bin/sh

files=("ft_putchar.c" "ft_swap.c" "ft_putstr.c" "ft_strlen.c" "ft_strcmp.c")

for file in ${files[@]}; do
	cc -Wall -Wextra -Werror -c $file
done
ar -rs libft.a *.o
rm *.o
