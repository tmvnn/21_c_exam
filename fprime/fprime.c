/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 12:04:06 by exam              #+#    #+#             */
/*   Updated: 2019/06/20 14:23:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(long num)
{
	long i;

	i = 1;
	while (++i < num)
		if (num % i == 0)
			return (0);
	return (1);
}

void	print_factor(long num)
{
	long ost;
	long i;

	ost = num;
	while (ost != 0)
	{
		i = 1;
		while (++i < ost)
		{
			if (is_prime(i) && (ost % i == 0))
			{
				printf("%ld*", i);
				break;
			}
		}
		ost /= i;
		if (is_prime(ost))
		{
			printf("%ld", ost);
			break;
		}
	}	
}

int		main(int argc, char **argv)
{
	long num;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num > 0)
		{
			if (num == 1 || num == 2 || is_prime(num))
				printf("%ld", num);
			else
				print_factor(num);
		}
	}
	printf("\n");
	return (0);
}
