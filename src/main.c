/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 20:17:58 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pick_binary(char *line)
{
		if (ft_strncmp(line, ".", 1) == 0)
			return (1);
		else
			return (2);
	return (0);
}

void	choose_binary(char *line, char **env)
{
	char	**argv;
}
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
		else if ((builtins = pick_binary(&split[i][j])) > 0)
			return (choose_binary(builtins));
		else
			ft_fprintf(2, &
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
