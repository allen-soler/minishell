/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:58:17 by jallen            #+#    #+#             */
/*   Updated: 2019/02/07 18:10:55 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_get_builtins(char *line)
{
	if (ft_strncmp(line, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "cd", 2) == 0)
		return (2);
	else
		return (0);
}

void	ft_builtins(char *line, int nb, char **env)
{
	if (nb == 1)
		ft_echo(line, env);
	if (nb == 2)
		ft_cd(line, env);
}

void	ft_echo(char *line, char **env)
{
	char	**split;
	//char	*tmp;
	int		i;
//	int		j;
(void)env;
	i = remove_spaces(&line[4]) + 4;
	split = ft_strsplit(&line[i], '"');
	i = 0;
	//tmp = NULL;
	while (split[i])
	{
	//	j = 0;
		/*while (split[i][j])
		{
		if (split[i] == '$')
		{
			tmp = ft_strjoin(&split[1], 	
		}
		j++;
		}*/
		i++;
	}
	ft_putchar('\n');
}
