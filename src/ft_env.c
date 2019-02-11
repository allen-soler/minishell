/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:02:36 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 17:31:58 by jallen           ###   ########.fr       */
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
				&& env[i][len] == '=')
			return (i);
		i++;
	}
	return (0);
}

char	**env_addr(char **env, char *src)
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
				&& env[i][len] == '=')
			return (env + i);
		i++;
	}
	return (NULL);
}

void	delete_env(char *name, char **env)
{
	char **ptr;
	char 	**tmp;

	ptr = env_addr(env, name);
	if (ptr)
	{
		tmp = ptr + 1;
		free(*ptr);
		while (tmp && *tmp)
		{
			*ptr =*tmp;
			ptr = tmp;
			tmp = tmp +1;
		}
		*ptr = NULL;
	}
}

char	**ft_unset_env(char **name, char **env)
{
	while (name && *name)
	{
		delete_env(*name, env);
		ptr = env_addr(env, *name)
		name = name + 1;		
	}
	return (env);
}

int		ft_setenv(char *name, char *new, char **env)
{
	char	*tmp;
	int		i;
	int		len;

	tmp = NULL;
	i = 0;
	len = tab_counter(env);
	if (env == NULL || name == NULL)
		return (0);
	if (ft_getenv(env, name))
	{
		i = ft_get_index(env, name);
		free(env[i]);
		tmp = ft_strjoin(name, "=");
		env[i] = (new == NULL) ? ft_strdup(tmp) : ft_strjoin(tmp, new);
		free(tmp);
	}
	else
	{
		tmp = ft_strjoin(name, "=");
		env[len] = (new == NULL) ? ft_strdup(tmp) : ft_strjoin(tmp, new);
		free(tmp);
		env[len + 1] = NULL;
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
				&& env[i][len] == '=')
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
