/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 15:01:23 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_exit(char **av)
{
	int	len;

	len = tab_counter(av);
	if (len > 2)
		ft_fprintf(2, "exit: too many arguments\n");
	else if (ft_strcmp(av[0], "exit") == 0)
	{
		free_array(av);
		exit(EXIT_SUCCESS);
	}
}

static void	check_command(char *line, char **env)
{
	char	**av;
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ';');
	while (split[i])
	{
		av = ft_split_whitespaces(split[i]);
		if (ft_strcmp(av[0], "exit") == 0)
			ft_exit(av);
		else if (check_builtins(av[0]) == 1)
			picking_builtins(av, split[i], env);
		else if (split[i][0] == '.')
			ft_local_binary(av, env);
		else
			ft_binary(av, env);
		free_array(av);
		i++;
	}
	free_array(split);
}

static char	*home_path(char *home, char **env)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_strlen(ft_getenv(env, "HOME"));
	if (ft_strcmp(ft_getenv(env, "HOME"), ft_getenv(env, "PWD")) == 0)
		home = ft_strdup(ft_getenv(env, "PWD"));
	else if ((tmp = ft_strdup(ft_getenv(env, "PWD"))))
	{
		home = ft_strjoin("~", &tmp[len]);
		free(tmp);
	}
	return (home);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	*home;

	(void)ac;
	(void)av;
	env = malloc_env(env);
	home = NULL;
	while (69)
	{
		//signal(SIGINT, SIG_IGN);
		home = home_path(home, env);
		ft_printf("{r}%s>{R} ", home);
		get_next_line(0, &line);
		if (home)
			free(home);
		if (line)
			check_command(line, env);
		free(line);
	}
	return (0);
}
