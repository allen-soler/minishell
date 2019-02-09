/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:02:36 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 19:25:33 by jallen           ###   ########.fr       */
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

int		ft_get_index(char **env, char *src)
{
	int		i;
	int		len;

	i = 0;
	if (env == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	while (env[i])
	{
		if (ft_strncmp(env[i], src, len) == 0
				&& env[i][len] == '=' )
			return (i);
		i++;
	}
	return (0);
}

int		ft_setenv(char *name, char *new, char **env)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	tmp = NULL;
	tmp1 = NULL;
	i = 0;

	if (env == NULL || name == NULL)
		return (0);
	if ((tmp = ft_getenv(env, name)))
	{
		i = ft_get_index(env, name);
		free(env[i]);
		tmp1 = ft_strjoin(name, "=");
		env[i] = ft_strjoin(tmp1, new);
		free(tmp1);
	}
	return (1);
}

char	*ft_getenv(char **env, char *src)
{
	int		i;
	int		len;

	i = 0;
	if (env == NULL || src == NULL)
		return (NULL);
	len = ft_strlen(src);
	while (env[i])
	{
		if (ft_strncmp(env[i], src, len) == 0
				&& env[i][len] == '=' )
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
