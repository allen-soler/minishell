/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:07:36 by jallen            #+#    #+#             */
/*   Updated: 2019/02/28 16:56:46 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		remove_user(char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		if (dest[i] == '/')
			j++;
		if (j == 3)
			break ;
		i++;
	}
	return (i);
}

void	simple_handler(int signal_nb)
{
	char	pwd[4097];
	char	*dest;

	dest = NULL;
	if (signal_nb == SIGINT)
	{
		if (getcwd(pwd, sizeof(pwd)) != NULL)
		{
			dest = ft_strdup(pwd);
			ft_printf("\n{c}~%s/{R}{r}$>{R}", &dest[remove_user(dest)]);
			free(dest);
		}
		else
			ft_printf("\n{c}>${R}");
		signal(SIGINT, simple_handler);
	}
}

void	program_handler(int signal_nb)
{
	if (signal_nb == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, program_handler);
	}
}
