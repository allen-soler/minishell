/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:35 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 19:33:13 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_echo_flags(char *av, short *r, int j)
{
	int	i;

	i = 1;
	(void)j;
	while (av[i])
	{
		if (av[i] == 'E' && i++)
			*r |= E;
		else if (av[i] == 'e' && i++)
			*r |= EE;
		else if (av[i] == 'n' && i++)
			*r |= N;
		else
			return ;
	}
}

static void	ft_check_f(char *av, int *i, short *r)
{
	int	j;
	int	ok;

	ok = 0;
	*i = 0;
	while (av[*i] != '\0')
	{
		j = 1;
		if (av[*i] == '-')
		{
			while (av[*i + j] != 32 && av[*i + j] != '\t' && av[*i + j])
			{
				if (av[*i + j] != 'n' && av[*i + j] != 'e'
						&& av[*i + j] != 'E')
					return ;
				j++;
			}
			ft_echo_flags(&av[*i], r, j);
			*i = *i + j;
		}
		if (av[*i] == 32 || av[*i] == '\t')
			*i = *i + 1;
		else
			break ;
	}
}

void		ft_echo(char *av, char **env)
{
	int		i;
	int		j;
	char	**argv;
	short	r;

	r = 0;
	i = 0;
	ft_check_f(av, &i, &r);
	argv = ft_split_whitespaces(&av[i]);
	ft_checking_av(argv, env);
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '"')
				ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar(32);
		i++;
	}
	(r & N) == 0 ? ft_putchar('\n') : 0;
	free_array(argv);
}
