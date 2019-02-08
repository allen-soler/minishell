/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:38:00 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 13:56:41 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_setpwd(char *name, char *value, char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	if (env == NULL || name == NULL)
		return (0);
	if ((pwd = getcwd(pwd, sizeof(pwd))))
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
				env[i] = ft_strjoin("PWD=", pwd);
			if (ft_strncmp(env[i], "OLDPWD", ft_strlen("OLDPWD")) == 0)
				env[i] = ft_strjoin("OLDPWD=", value);
			i++;
		}
		free(pwd);
	}
	return (0);
}

static void	ft_single_cd(char **env)
{
	char	*user;
	char	*cwd;

	cwd = NULL;
	user = ft_strjoin("/Users/", ft_getenv(env, "USER"));
	if ((cwd = getcwd(cwd, sizeof(cwd))))
	{
		chdir(user);
		ft_setpwd("PWD", cwd, env);
		free(cwd);
	}
	free(user);
}

static void	ft_cd_access(char **av, char **env)
{
	char	*cwd;

	cwd = NULL;
	if (av[0] && av[1] == NULL)
	{
		if (access(av[0], F_OK) == 0)
		{
			if ((access(av[0], W_OK) == 0 || av[0][0] == '/')
					&& (cwd = getcwd(cwd, sizeof(cwd)))
					&& chdir(av[0]) == 0)
			{
				ft_setpwd("PWD=", cwd, env);
				free(cwd);
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
	char	*cwd;

	cwd = NULL;
	if (av[0] == NULL)
		ft_single_cd(env);
	else if (av[0][0] == '-' && ft_strlen(av[0]) == 1 && av[1] == NULL
			&& (cwd = getcwd(cwd, sizeof(cwd))))
	{
		tmp = ft_getenv(env, "OLDPWD=");
		chdir(tmp);
		ft_setpwd("PWD", cwd, env);
		free(cwd);
	}
	else if (av[0])
		ft_cd_access(av, env);
}
