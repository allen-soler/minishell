/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:53:10 by jallen            #+#    #+#             */
/*   Updated: 2019/02/27 18:44:13 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cnt_index(char *src)
{
	int	i;

	i = 1;
	while (src[i])
	{
		if (ft_isdigit(src[i]) == 0 && ft_isalpha(src[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

int		remove_spaces(char *split)
{
	int		i;

	i = 0;
	while (split)
	{
		if (split[i] != ' ' && split[i] != '	')
			break ;
		i++;
	}
	return (i);
}

void	ft_checking_var(char **av, char **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	i = 0;
	while (av[i])
	{
		if (av[i][0] == '$')
		{
			tmp = ft_strndup(av[i], cnt_index(av[i]));
			if (ft_getenv(env, &tmp[1]) == NULL)
			{
				free(tmp);
				return ;
			}
			tmp2 = ft_strdup(&av[i][cnt_index(av[i])]);
			free(av[i]);
			av[i] = ft_strjoin(ft_getenv(env, &tmp[1]), tmp2);
			free(tmp2);
			free(tmp);
		}
		i++;
	}
}

void	ft_checking_av(char **av, char **env)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (av[i] && ft_strlen(ft_getenv(env, "HOME")) > 0)
	{
		if (av[i][0] == '~' && av[i][1] == '/')
		{
			tmp = ft_strdup(av[i]);
			free(av[i]);
			av[i] = ft_strjoin(ft_getenv(env, "HOME"), &tmp[1]);
			free(tmp);
		}
		else if (ft_strcmp(av[i], "~") == 0)
		{
			free(av[i]);
			av[i] = ft_strdup(ft_getenv(env, "HOME"));
		}
		i++;
	}
	ft_checking_var(av, env);
}

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
