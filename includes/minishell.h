/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:43 by jallen            #+#    #+#             */
/*   Updated: 2019/02/05 19:27:36 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libftprintf/includes/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
/*
**	FLAGS
*/ 
# define N (1 << 0)

void	free_array(char **tab);
char	*ft_getenv(char **env, char *src);
int		remove_spaces(char *split);
void	ft_echo(char *line);
char	*checking_bin(char **paths, char *line);
void	ft_binary(char *line, char **env);
void	check_command(char *line, char **env);

