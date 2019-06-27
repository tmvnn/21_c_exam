/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:02:26 by exam              #+#    #+#             */
/*   Updated: 2019/06/27 15:55:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

char	b_char(char c)
{
	if (c == '{')
		return ('}');
	if (c == '[')
		return (']');
	if (c == '(')
		return (')');
	return (0);
}

int		brackets(char *str, char c, char *b)
{
	if (*str == 0 && *b == '.')
		return (1);
	else if (*str == 0 && *b != '.')
		return (0);
	else if (*str == '{' || *str == '[' || *str == '(')
	{
		if(!brackets(str + 1, b_char(*str), str))
			return (0);
		//c = 0;
		if (*str == '.')
			return (1);
	}
	else if (*str == '}' || *str == ']' || *str == ')')
	{
		if (*str == c)
		{
			*str = '.';
			*b = '.';
			return (1);
		}
		else
			return (0);
	}
	return (brackets(str + 1, c, b));
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*(++argv))
		{
			(**argv == 0) || brackets(*argv, b_char(*argv[0]), argv[0]) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
