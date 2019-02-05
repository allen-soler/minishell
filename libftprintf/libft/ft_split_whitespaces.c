/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:33:37 by jallen            #+#    #+#             */
/*   Updated: 2019/02/05 14:36:29 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] != 32 && src[i] != '\n' && src[i] != '\t' && src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int			ft_count_array(char *str)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (str[0] != 32 && str[0] != '\t' && str[0] != '\n')
		counter++;
	while (str[i] != '\0')
	{
		if (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
			if (str[i - 1] == 32 || str[i - 1] == '\n' || str[i - 1] == '\t')
				counter++;
		i++;
	}
	return (counter);
}

void		ft_add_str(char *str, char **tab)
{
	int		i;
	int		counter_tab;

	i = 0;
	counter_tab = 0;
	if (str[0] != 32 && str[0] != '\n' && str[0] != '\t')
	{
		tab[counter_tab] = ft_dup(str);
		counter_tab++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
			if (str[i - 1] == 32 || str[i - 1] == '\n' || str[i - 1] == '\t')
			{
				tab[counter_tab] = ft_dup(&str[i]);
				counter_tab++;
			}
		i++;
	}
}

char		**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		tab_len;

	tab_len = ft_count_array(str);
	tab = malloc(sizeof(char *) * (1 + tab_len));
	if (!tab)
		return (NULL);
	ft_add_str(str, tab);
	tab[tab_len] = 0;
	return (tab);
}
