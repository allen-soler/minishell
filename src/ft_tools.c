/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:53:10 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 18:31:45 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **tab)
{
	char	**ptr;

	ptr = tab;
	while (tab && *tab)
	{
		free(*tab);
		tab++;
	}
	(ptr) ? free(ptr) : 0;
}

int		remove_spaces(char *split)
{
	int		i;

	i = 0;
	while (split)
	{
		if (split[i] != ' ' && split[i] != '	')
			break ;
		i++;
	}
	return (i);
}
