/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:04:38 by exam              #+#    #+#             */
/*   Updated: 2019/06/29 13:44:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include <stdio.h>

void	init_stack(t_st *stack)
{
	int i;

	i = -1;
	while (++i < N)
	{
		stack[i].c = 0;
		stack[i].i = -1;
	}
}

void	print_stack(t_st *stack)
{
	int i;

	i = -1;
	while (stack[++i].c)
		printf("%c %i\n", stack[i].c, stack[i].i);
}

void	push(t_st *stack, char c, int i)
{
	stack->c = c;
	stack->i = i;
}

char	inv_br(char c)
{
	if (c == ')')
		return ('(');
	if (c == ']')
		return ('[');
	if (c == '}')
		return ('{');
	return (0);
}

int		pop(t_st *stack, char *c, char *str)
{
	if (stack->c == inv_br(*c))
	{
		stack->c = 0;
		str[stack->i] = '.';
		*c = '.';
		stack->i = -1;
		return (1);
	}
	return (0);
}

int		brackets(char *str)
{
	t_st 	stack[N];
	int		d;
	int		i;

	d = -1;
	init_stack(stack);
	i = -1;
	while (str[++i])
	{
		printf("str = '%s'   str[i] =%c\n", str, str[i]);
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			push(&stack[++d], str[i], i);
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (pop(&stack[d], &str[i], str))
			{
				if (--d < -1)
					return (0);
			}
			else
				return (0);
		}
	}
	printf("str = '%s'\n", str);
	if (stack[0].c)
		return (0);
	print_stack(stack);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*(++argv))
		{
			brackets(*argv) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
		}
		return (1);
	}
	write(1, "\n", 1);
	return (0);
}
