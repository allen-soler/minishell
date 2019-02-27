/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/27 18:45:31 by jallen           ###   ########.fr       */
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
		if (av[0])
		{
			if (ft_strcmp(av[0], "exit") == 0)
				ft_exit(av);
			else if (check_builtins(av[0]) == 1)
				picking_builtins(av, split[i], env);
			else if ((av[0][0] == '.' || av[0][0] == '/'))
				ft_local_binary(av, env);
			else
				ft_binary(av, env);
		}
		free_array(av);
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
		ft_printf("{r}$>{R}");
		signal(SIGINT, simple_handler);
		get_next_line(0, &line);
		if (line)
		{
			check_command(line, env);
			free(line);
		}
	}
	return (0);
}
