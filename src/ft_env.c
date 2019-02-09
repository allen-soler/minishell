/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:02:36 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 18:43:08 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**malloc_env(char **env)
{
	size_t	i;

	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i])
	{
		env[i] = ft_strdup(env[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		ft_setenv(char *name, char *new, char **env)
{
	char	*tmp;

	tmp = NULL;
	if (env == NULL || name == NULL)
		return (0);
	if ((tmp = ft_getenv(env, name)))
	{
				
	}
	return (1);
}

char	*ft_getenv(char **env, char *src)
{
	int		i;

	i = 0;
	if (env == NULL || src == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], src, ft_strlen(src)) == 0)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
