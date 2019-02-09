/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 14:19:17 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_invcommand(char *line)
{
	char	**av;

	av = ft_split_whitespaces(line);
	ft_fprintf(2, "minishell: command not found: %s\n", av[0]);
	free_array(av);
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
		if (builtins > 0)
			ft_builtins(&split[i][j], builtins, env);
		else if ((builtins = pick_binary(&split[i][j])) > 0)
			return (choose_binary(line, env, builtins));
		else
			ft_invcommand(line);
		i++;
	}
	free_array(split);
}

int			main(int ac, char **av, char **env)
{
	char	*line;

	(void)ac;
	(void)av;
	while (69)
	{
		//signal(SIGINT, SIG_IGN);
		ft_printf("{r}$>{R} ");
		get_next_line(0, &line);
		if (ft_strcmp(&line[remove_spaces(line)], "exit") == 0)
			exit(EXIT_SUCCESS);
		if (line)
			check_command(line, env);
		free(line);
	}
	return (0);
}
