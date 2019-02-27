/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:07:36 by jallen            #+#    #+#             */
/*   Updated: 2019/02/27 16:07:38 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	simple_handler(int signal_nb)
{
	if (signal_nb == SIGINT)
	{
		ft_putstr("\n");
		ft_printf("{r}$>{R}");
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
