/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:38:00 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 17:55:04 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_setpwd(char *value, char **env)
{
	int		i;
	char	pwd[4097];

	i = 0;
	if (env == NULL)
		return (0);
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], "PWD=", ft_strlen("PWD=")) == 0)
				ft_strcpy(&env[i][4], pwd);
			if (ft_strncmp(env[i], "OLDPWD=", ft_strlen("OLDPWD=")) == 0)
				ft_strcpy(&env[i][7], value);
			i++;
		}
	}
	return (0);
}

static void	ft_single_cd(char **env)
{
	char	*user;
	char	cwd[4097];

	user = ft_strjoin("/Users/", ft_getenv(env, "USER"));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		chdir(user);
		ft_setpwd(cwd, env);
	}
	free(user);
}

static void	ft_cd_access(char **av, char **env)
{
	char	cwd[4097];

	if (av[0] && av[1] == NULL)
	{
		if (access(av[0], F_OK) == 0)
		{
			if ((access(av[0], W_OK) == 0 || av[0][0] == '/')
					&& getcwd(cwd, sizeof(cwd))
					&& chdir(av[0]) == 0)
			{
				chdir(av[0]);
				ft_setpwd(cwd, env);
			}
			else if (access(av[0], W_OK) == -1)
				ft_fprintf(2, "cd: permission denied: %s\n", av[0]);
			else
				ft_fprintf(2, "cd: directory: %s\n", av[0]);
		}
		else
			ft_fprintf(2, "cd: directory: %s\n", av[0]);
	}
	else if (av[1])
		ft_fprintf(2, "cd: string not in pwd: %s\n", av[0]);
}

void		ft_cd(char **av, char **env)
{
	char	*tmp;
	char	cwd[4097];

	if (av[0] == NULL)
		ft_single_cd(env);
	else if (av[0][0] == '-' && ft_strlen(av[0]) == 1 && av[1] == NULL
			&& getcwd(cwd, sizeof(cwd)) != NULL)
	{
		tmp = ft_getenv(env, "OLDPWD=");
		chdir(tmp);
		ft_setpwd(cwd, env);
	}
	else if (av[0])
		ft_cd_access(av, env);
}
