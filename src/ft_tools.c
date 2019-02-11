/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:53:10 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 10:30:36 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **tab)
{
	char	**ptr;

	ptr = tab;
	while (tab && *tab)
	{
		free(*tab);
		tab++;
	}
	(ptr) ? free(ptr) : 0;
}

int		tab_counter(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int		remove_spaces(char *split)
{
	int		i;

	i = 0;
	while (split)
	{
		if (split[i] != ' ' && split[i] != '	')
			break ;
		i++;
	}
	return (i);
}

void	ft_checking_av(char **av, char **env)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (av[i])
	{
		if (av[i][0] == '~' && av[i][1] == '/')
		{
			tmp = ft_strdup(av[i]);
			free(av[i]);
			av[i] = ft_strjoin(ft_getenv(env, "HOME"), &tmp[1]);
			free(tmp);
		}
		else if (ft_strcmp(av[i], "~") == 0)
		{
			free(av[i]);
			av[i] = ft_strdup(ft_getenv(env, "HOME"));
		}
		i++;
	}
}
