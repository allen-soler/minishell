/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/04 17:14:38 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		remove_spaces(char *split)
{
	int		i;

	i = 0;
	while (split)
	{
		if (split[i] != ' ' && split[i] != '	')
			break;
		i++;
	}
	return (i);
	
}
void	ft_echo(char *line)
{
	int		i;

	i = remove_spaces(&line[4]) + 4;
	ft_printf("%s\n", &line[i]);
	while (line[i])
	{	
		i++;
	}
}

void	check_command(char *line)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_strsplit(line, ';');
	while(split[i])
	{
		j = remove_spaces(split[i]);
		if (ft_strncmp(&split[i][j],"echo", 4) == 0)
			ft_echo(&split[i][j]);
		i++;
	}

}

int		main(int ac, char **av, char **env)
{
	char	*line;
	(void)ac;
	(void)av;
	(void)env;

	while (69)
	{
		ft_printf("$>");
		get_next_line(0, &line);
		check_command(line);
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
