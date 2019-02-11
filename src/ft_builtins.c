/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:58:17 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 20:07:55 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_builtins(char *av)
{
	if (ft_strcmp(av, "echo") == 0)
		return (1);
	else if (ft_strcmp(av, "cd") == 0)
		return (1);
	else if (ft_strcmp(av, "env") == 0)
		return (1);
	else if (ft_strcmp(av, "setenv") == 0)
		return (1);
	else if (ft_strcmp(av, "unsetenv") == 0)
		return (1);
	return (0);
}

void	picking_builtins(char **av, char *line, char **env)
{
	if (ft_strcmp(av[0], "env") == 0 && tab_counter(av) == 1)
		ft_print_tab(env);
	else if (ft_strcmp(av[0], "echo") == 0)
		ft_echo(&line[remove_spaces(line) + 4], env);
	else if (ft_strcmp(av[0], "cd") == 0)
		ft_cd(&av[1], env);
	else if (ft_strcmp(av[0], "setenv") == 0)
	{
		if (tab_counter(av) > 3)
		{
			ft_fprintf(2, "setenv : Too many arguments\n");
			return ;
		}
		ft_setenv(av[1], av[2], env);
	}
	else if (ft_strcmp(av[0], "unsetenv") == 0)
		env = ft_unset_env(&av[1], env);
}
