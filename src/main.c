/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/06 16:53:06 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **tab)
{
	while (tab && *tab)
	{
		if (*tab)
			free(*tab);
		tab++;
	}
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

void	ft_echo(char *line)
{
	int		i;
	char	**split;

	i = remove_spaces(&line[4]) + 4;
	split = ft_strsplit(&line[i], '"');
	i = 0;
	while (split[i])
	{
		ft_printf("%s ", split[i]);
		i++;
	}
	ft_putchar('\n');
}

char	*checking_bin(char **paths, char *line)
{
	char		*dest;
	char		*tmp;
	struct stat	sb;

	tmp = 0;
	int i = 0;
	while (*paths)
	{
		tmp = ft_strjoin(paths[i], "/");
		dest = ft_strjoin(tmp, line);
		free(tmp);
		if (stat(dest, &sb) == 0 && sb.st_mode & S_IXUSR)
			return (dest);
		free(dest);
		i++;
	}
	return (NULL);
}

int		check_local_bin(char *dest)
{
	struct stat	sb;

	if (stat(dest, &sb) == 0 && sb.st_mode & S_IXUSR)
		return (1);
	return (0);
}

void	ft_local_binary(char *line)
{
	char	**argv;
	pid_t	pid;

	argv = ft_split_whitespaces(line);
	if (check_local_bin(argv[0]) == 1)
	{
		pid = fork();
		if (pid == 0)
			execve(argv[0], &argv[0], NULL);
		wait(&pid);
		kill(pid, EXIT_SUCCESS);
	}
	free_array(argv);
}

void	ft_binary(char *line, char **env)
{
	char	**argv;
	char	*dest;
	char	**paths;
	pid_t	pid;

	argv = ft_split_whitespaces(line);
	paths = ft_strsplit(ft_getenv(env, "PATH"), ':');
	dest = checking_bin(paths, argv[0]);
	if (dest)
	{
		pid = fork();
		if (pid == 0)
			execve(dest, &argv[0], env);
		wait(&pid);
		kill(pid, EXIT_SUCCESS);
		free_array(paths);
		free(dest);
	}
	free_array(argv);
}

void	check_command(char *line, char **env)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_strsplit(line, ';');
	while (split[i])
	{
		j = remove_spaces(split[i]);
		if (ft_strncmp(&split[i][j], "echo", 4) == 0)
			ft_echo(&split[i][j]);
		else if (ft_strncmp(&split[i][j], ".", 1) == 0)
			ft_local_binary(&split[i][j]);
		else
			ft_binary(&split[i][j], env);
		i++;
	}
	free_array(split);
}

int		main(int ac, char **av, char **env)
{
	char	*line;

	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	while (69)
	{
		ft_printf("{r}$>{R} ");
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		if (line)
			check_command(line, env);
		free(line);
	}
	return (0);
}
