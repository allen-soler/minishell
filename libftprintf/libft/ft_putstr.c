/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:28:26 by jallen            #+#    #+#             */
/*   Updated: 2018/11/15 11:28:28 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!(str))
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
