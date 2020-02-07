/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:52:01 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/07 15:14:10 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

void    print_usage()
{
    write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}

void    print_invalid_option()
{
    write(1, "Invalid Option\n", 15);
}

int		option_is_ok(char **argv)
{
    char	out[32] = {0};
    int		i;

    while (*(++argv))
    {
		if ((*argv)[0] == '-')
		{
			i = 1;
			while ((*argv)[i] && (*argv)[i] >= 'a' && (*argv)[i] <= 'z')
			{
				if ((*argv)[i] == 'h')
				{
					print_usage();
					return 1;
				}
				
				out['z' - (*argv)[i] + 6] = 1;
				
				i++;
			}
			
			if ((*argv)[i])
					return 0;
		}	
    }
	i = -1;
	while (++i < 32)
	{
		out[i] = out[i] + '0';
		write(1, &out[i], 1);
		if (i + 1 == 32)
			write(1, "\n", 1);
		else if ((i + 1) % 8 == 0)
			write(1, " ", 1);
	}
    return 1;
}

int     main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (!(option_is_ok(argv)))
            print_invalid_option();
        else
            return 1;
    }
    else
        print_usage();
    return 0;
}