/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:35 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 14:28:03 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_echo_flags(char av, short r)
{
	if (av[i] == 'E')
		r |= E;
	else if (av[i] == 'E')
		r |= EE;
	else if (av[i] == 'n')
		r |= N;
}

static void	ft_check_f(char *av, int *i, short r)
{
	int	j;
	(void)r;
	*i = 0;
	while (av[*i] && av[*i][0] == '-')
	{
		j = 1;
		while (av[*i][j])
		{
			if (!ft_strchr("Een", av[*i][j]))
				return ;
			j++;
		}
		ft_echo_flags(av[*i], r);
		*i = *i + 1;
	}
}

void	ft_echo(char *av, char **env)
{
	short	r;
	int		i;
	int		j;

	r = 0;
	ft_check_f(av, &i, r);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '~')
				ft_printf("%s/", ft_getenv(env, "HOME="));
			else
				ft_putchar(av[i][j]);
			j++;
		}
		i++;
	}
	if ((r & N) == 0)
		ft_putchar('\n');
}
