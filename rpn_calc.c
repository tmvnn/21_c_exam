/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:01:40 by exam              #+#    #+#             */
/*   Updated: 2019/06/22 15:41:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

void	push(t_nums **lst, int num)
{
	t_nums *new;

	if (!(new = (t_nums*)malloc(sizeof(t_nums))))
		return;
	new->n = num;
	if (*lst == 0)
	{
		new->next = 0;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	print_lst(t_nums *lst)
{
	if (lst)
	{
		while (lst)
		{
			printf("%d", lst->n);
			lst = lst->next;
		}
		printf("\n");
	}
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int     is_oper(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		do_op(int n1, int n2, char op)
{
	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (op == '/')
		return (n1 / n2);
	if (op == '%')
		return (n1 % n2);
	return (0);
}

int		pop(t_nums **lst, char op)
{
	int		res;
	t_nums *tmp;

	res = 0;
	if (*lst && (*lst)->next)
	{
		res = do_op((*lst)->next->n, (*lst)->n, op);
		(*lst)->n = res;
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		free(tmp);
		return (1);
	}
	return (0);
}

int		calc(char *str)
{
	t_nums	*lst;
	int		i;

	lst = 0;
	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
		{
			if (i > 0)
			{
				if (str[i - 1] == '-')
					push(&lst, atoi(str + i - 1));
				else
					push(&lst, atoi(str + i));
			}
			else
				push(&lst, atoi(str + i));
			while (is_digit(str[i]))
				i++;
		}
		else if (is_oper(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			if(pop(&lst, str[i]))
				i++;
			else
				return (0);
		}
		else if (str[i] == ' ' || (str[i] == '-' && is_digit(str[i + 1])))
			i++;
		else
			return (0);
	}
	if (lst == 0 || lst->next)
		return (0);
	print_lst(lst);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (calc(argv[1]))
			return (1);
	}
	printf("Error\n");
	return (0);
}
