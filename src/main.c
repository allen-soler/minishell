/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:18 by jallen            #+#    #+#             */
/*   Updated: 2019/02/28 17:29:41 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_exit(char **av)
{
	int	len;

	len = tab_counter(av);
	if (len > 2)
		ft_fprintf(2, "exit: too many arguments\n");
	else if (ft_strcmp(av[0], "exit") == 0)
	{
		free_array(av);
		exit(EXIT_SUCCESS);
	}
}

static void	check_command(char *line, char **env)
{
	char	**av;
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ';');
	while (split[i])
	{
		av = ft_split_whitespaces(split[i]);
		if (av[0])
		{
			ft_checking_av(av, env);
			if (ft_strcmp(av[0], "exit") == 0)
				ft_exit(av);
			else if (check_builtins(av[0], av) == 1)
				picking_builtins(av, split[i], env);
			else if ((av[0][0] == '.' || av[0][0] == '/'))
				ft_local_binary(av, env);
			else
				ft_binary(av, env);
		}
		free_array(av);
		i++;
	}
	free_array(split);
}

static char	*get_pwd(char **env)
{
	char	*dest;
	char	*tmp;
	char	pwd[4097];
	int		i;

	dest = NULL;
	tmp = NULL;
	if (env == NULL)
		return (0);
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		if (ft_strcmp("/", pwd) == 0)
		{
			dest = ft_strdup("");
			return (dest);
		}
		dest = ft_strdup(pwd);
		i = ft_strlen(ft_getenv(env, "HOME"));
		tmp = ft_strjoin("~", &dest[i]);
		free(dest);
	}
	return (tmp);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	*pwd;

	(void)ac;
	(void)av;
	env = malloc_env(env);
	pwd = NULL;
	while (69)
	{
		pwd = get_pwd(env);
		ft_printf("{c}%s/{R}{r}$>{R}", pwd);
		signal(SIGINT, simple_handler);
		get_next_line(0, &line);
		if (line)
		{
			check_command(line, env);
			free(line);
		}
		if (pwd)
			free(pwd);
	}
	return (0);
}
