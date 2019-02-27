/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:38:00 by jallen            #+#    #+#             */
/*   Updated: 2019/02/27 16:08:35 by jallen           ###   ########.fr       */
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
		ft_setenv("PWD", pwd, env);
		ft_setenv("OLDPWD", value, env);
	}
	return (0);
}

static int	valid_dir(char *av)
{
	struct stat f_stat;

	if (stat(av, &f_stat) == 0 && (S_ISDIR(f_stat.st_mode)
				|| S_ISLNK(f_stat.st_mode)))
		return (1);
	ft_fprintf(2, "cd: is not a directory: %s\n", av);
	return (0);
}

static int	is_access(char *av)
{
	if (access(av, F_OK) == 0)
		return (1);
	ft_fprintf(2, "cd: no such file or directory: %s\n", av);
	return (0);
}

static int	is_exec(char *av)
{
	if (access(av, X_OK) == 0)
		return (1);
	ft_fprintf(2, "cd: permission denied: %s\n", av);
	return (0);
}

void		ft_cd(char **av, char **env)
{
	char	cwd[4097];
	char	*path;
	int		len;

	len = tab_counter(av);
	ft_checking_av(av, env);
	if (len > 1)
		ft_fprintf(2, "cd: string not in pwd: %s\n", av[0]);
	path = (len == 0) ? ft_getenv(env, "HOME") : av[0];
	path = (path && ft_strcmp(path, "--") == 0) ? ft_getenv(env, "HOME") : path;
	path = (path && ft_strcmp(path, "-") == 0)\
		? ft_getenv(env, "OLDPWD") : path;
	if (path && is_access(path) && valid_dir(path) && is_exec(path))
	{
		getcwd(cwd, sizeof(cwd));
		chdir(path);
		ft_setpwd(cwd, env);
	}
}
