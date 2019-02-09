/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:58:17 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 18:56:52 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_get_builtins(char *line)
{
	char	**av;

	av = ft_split_whitespaces(line);
	if (ft_strcmp(av[0], "echo") == 0)
	{
		free_array(av);
		return (1);
	}
	else if (ft_strcmp(av[0], "cd") == 0)
	{
		free_array(av);
		return (2);
	}
	free_array(av);
	return (0);
}

void	ft_checking_av(char **av, char **env)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '~')
		{
			if (av[i][1] == '/')
			{
				free(av[0]);
				av[i] = ft_strjoin(ft_getenv(env, "HOME="), &av[i][1]);
			}
			else if (ft_strlen(av[i]) == 1)
			{
				free(av[i]);
				av[i] = ft_strdup(ft_getenv(env, "HOME="));
			}
		}
		i++;
	}
}

void	ft_builtins(char *line, int nb, char **env)
{
	char	**av;

	av = NULL;
	if (nb == 1)
		ft_echo(&line[remove_spaces(&line[4]) + 4], env);
	if (nb == 2)
	{
		av = ft_split_whitespaces(&line[2]);
		ft_checking_av(av, env);
		ft_cd(av, env);
		free_array(av);
	}
}
