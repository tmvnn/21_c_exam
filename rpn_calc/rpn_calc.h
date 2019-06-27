/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:03:22 by exam              #+#    #+#             */
/*   Updated: 2019/06/22 15:33:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_CALC_H
# define RPN_CALC_H

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_nums
{
	int				n;
	struct s_nums	*next;
}					t_nums;

#endif
