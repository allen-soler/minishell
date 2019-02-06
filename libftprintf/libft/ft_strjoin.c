/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:11:20 by jallen            #+#    #+#             */
/*   Updated: 2019/02/06 19:31:48 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;
	char *ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
				+ 1)))
		return (NULL);
	ptr = ret;
	if (!ret)
		return (NULL);
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (ptr);
}
