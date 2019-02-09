/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:50:58 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 17:31:35 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*checking_bin(char **paths, char *line)
{
	char		*dest;
	char		*tmp;
	struct stat	sb;

	tmp = 0;
	while (paths && *paths)
	{
		tmp = ft_strjoin(*paths, "/");
		dest = ft_strjoin(tmp, line);
		free(tmp);
		if (stat(dest, &sb) == 0 && sb.st_mode & S_IXUSR)
			return (dest);
		free(dest);
		paths++;
	}
	return (NULL);
}

static int	check_local_bin(char *dest)
{
	struct stat	sb;

	if (stat(dest, &sb) == 0 && sb.st_mode & S_IXUSR)
		return (1);
	return (0);
}

void		ft_local_binary(char *line, char **env)
{
	char	**argv;
	pid_t	pid;
	int		i;

	i = 0;
	argv = ft_split_whitespaces(line);
	ft_checking_av(argv, env);
	if (check_local_bin(argv[0]) == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], &argv[0], NULL);
			exit(EXIT_SUCCESS);
		}
		wait(&pid);
		kill(pid, EXIT_SUCCESS);
	}
	else
		ft_fprintf(2, "minishell: command not found : %s\n", argv[0]);
	free_array(argv);
}

void		ft_binary(char *line, char **env)
{
	char	**argv;
	char	*dest;
	char	**paths;
	pid_t	pid;

	paths = ft_strsplit(ft_getenv(env, "PATH"), ':');
	argv = ft_split_whitespaces(line);
	ft_checking_av(argv, env);
	dest = checking_bin(paths, argv[0]);
	if (dest)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(dest, &argv[0], env);
			exit(EXIT_SUCCESS);
		}
		wait(&pid);
		kill(pid, EXIT_SUCCESS);
		free(dest);
	}
	else
		ft_fprintf(2, "minishell: command not found : %s\n", argv[0]);
	free_array(paths);
	free_array(argv);
}
