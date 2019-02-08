/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:30:44 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 19:44:14 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = NULL;
	if (!(new_node = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		new_node->content = NULL;
	else
		new_node->content = ft_strdup(content);
	new_node->content_size = content_size;
	new_node->next = NULL;
	return (new_node);
}
