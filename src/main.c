/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 14:22:44 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_command(char *line, char **env)
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
		else if (ft_strncmp(&split[i][j], ".", 1) == 0)
			ft_local_binary(&split[i][j]);
		else
			ft_binary(&split[i][j], env);
		i++;
	}
	free_array(split);
}

int		main(int ac, char **av, char **env)
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
