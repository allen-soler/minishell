/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/05 16:11:42 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(char **env, char *src)
{
	char	*path;
	int		i;

	i = 0;
	if (env == NULL || src == NULL)
		return NULL;
	while(env[i])
	{
		if (ft_strncmp(env[i], src, ft_strlen(src)) == 0)
			path = ft_strchr(env[i], '=') + 1;
		i++;
	}
	return (path);
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
		free(split[i]);
		i++;
	}
	ft_putchar('\n');
}

char	*checking_bin(char **paths, char *line)
{
	char		*dest;
	char		*tmp;
	int			i;
	struct stat	sb;

	i = 0;
	tmp = 0;
	while (paths[i])
	{
		if (chdir(paths[i]) == 0)
		{
			tmp = ft_strjoin(paths[i], "/");
			dest = ft_strjoin(tmp, line);
			if (stat(dest, &sb) == 0 && sb.st_mode & S_IXUSR)
				return (dest);
			free(tmp);
			free(dest);
		}	
		i++;
	}
	return (NULL);
}
void	ft_binary(char *line, char **env)
{
	char 	**argv;
	char	**paths;
	char	*dest;

	paths = ft_strsplit(ft_getenv(env, "PATH"), ':');
	argv = ft_split_whitespaces(line);
	dest =checking_bin(paths, argv[0]);
	if (dest && fork() == 0)
		execve(dest, &argv[0], env);
	free(dest);
	free(line);
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
		else	
			ft_binary(&split[i][j], env);
		i++;
	}
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
		check_command(line, env);
		if (ft_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		free(line);
	}
	return (0);
}
