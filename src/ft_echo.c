/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:35 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 16:27:59 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
static void	ft_echo_flags(char *av, short r, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (av[0] == '-' && i++)
		{
			if (av[i] == 'E' && i++)
				r |= E;
			else if (av[i] == 'e' && i++)
				r |= EE;
			else if (av[i] == 'n' && i++)
				r |= N;
		}
	}
}

static void	ft_check_f(char *av, int *i, short r)
{
	int	j;

	*i = 0;
	while (av[*i])
	{
		j = 1;
		if (av[*i] == '-')
		{
			while (av[*i + j] != 32 && av[*i + j] != '\t' && av[*i + j])
			{
				if (av[*i + j] != 'n')
					return ;
				j++;
			}
			*i = *i + j;
			ft_echo_flags(&av[*i], r, j);
		}
		*i = *i + 1;
	}
}
*/
void	ft_echo(char *av, char **env)
{
//	short	r;
	int		i;
	char	**a;

	a = ft_obstacles(av);
	for(int j = 0; a[j]; j++)
		ft_printf("%s\n", a[j]);
	i = 0;
	(void)env;
//	ft_check_f(av, &i, r);
	while (av[i])
	{
		ft_putchar(av[i]);
		i++;
	}
	ft_putchar('\n');
}
