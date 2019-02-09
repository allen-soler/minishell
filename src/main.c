/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 18:41:18 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void ft_exit(char *line)
{
	char	**av;

	av = ft_split_whitespaces(line);
	if (ft_strcmp(av[0], "exit") == 0 && ft_strlen(av[1]) == 0)
	{
		free_array(av);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strcmp(av[0], "exit") == 0 && av[2] == NULL)
	{
		free_array(av);
		exit(EXIT_SUCCESS);
	}
	else if (av[2] != NULL)
		ft_fprintf(2, "exit: too many arguments\n");
	free(av);
}

static void	check_command(char *line, char **env)
{
	char	**split;
	int		i;
	int		j;
	int		builtins;

	i = 0;
	split = ft_strsplit(line, ';');
	while (split[i])
	{
		j = remove_spaces(split[i]);
		builtins = ft_get_builtins(&split[i][j]);
		if (ft_strncmp(&line[remove_spaces(line)], "exit", 4) == 0)
			ft_exit(&split[i][i]);
		if (builtins > 0)
			ft_builtins(&split[i][j], builtins, env);
		else if (split[i][0] == '.')
			ft_local_binary(split[i], env);
		else
			ft_binary(split[i], env);
		i++;
	}
	free_array(split);
}

int			main(int ac, char **av, char **env)
{
	char	*line;

	(void)ac;
	(void)av;
	env = malloc_env(env);
	while (69)
	{
		//signal(SIGINT, SIG_IGN);
		ft_printf("{r}$>{R} ");
		get_next_line(0, &line);
		if (line)
			check_command(line, env);
		free(line);
	}
	return (0);
}
