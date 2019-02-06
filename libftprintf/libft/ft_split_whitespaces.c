/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:33:37 by jallen            #+#    #+#             */
/*   Updated: 2019/02/06 17:47:45 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_blank(char c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

static size_t	count_words(char *str)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_blank(str[i]) && str[i] != '\0')
			count += 1;
		while (!is_blank(str[i]) && str[i + 1] != '\0')
			i += 1;
		i += 1;
	}
	return (count);
}

static size_t	ft_wl(char *str)
{
	size_t len;

	len = 0;
	while (!is_blank(str[len]) && str[len] != '\0')
		len++;
	return (len);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	size_t	nb_words;
	size_t	i;

	i = 0;
	nb_words = count_words(str);
	if (!str || !(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		while (*str != '\0' && is_blank(*str))
			str++;
		tab[i] = ft_strndup(str, ft_wl(str));
		while (!is_blank(*str) && *(str) != '\0')
			str++;
		i++;
	}
	tab[nb_words] = NULL;
	return (tab);
}
