/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:43 by jallen            #+#    #+#             */
/*   Updated: 2019/02/08 14:26:17 by jallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "../libftprintf/includes/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/xattr.h>
# include <termios.h>

/*
** FLAGS && Bonus
*/
# define E (1 << 0)
# define EE (1 << 1)
# define N (1 << 2)
/*
** Env bins + env functions
*/
char	*ft_getenv(char **env, char *src);
char	*checking_bin(char **paths, char *line);
void	ft_binary(char *line, char **env);
/*
** Local bins
*/
int		check_local_bin(char *dest);
void	ft_local_binary(char *line);
/*
** Builtins
*/
int		ft_get_builtins(char *line);
void	ft_cd(char **av, char **env);
void	ft_echo(char *av, char **env);
void	ft_builtins(char *line, int nb, char **env);
/*
** Parsing
*/
int		remove_spaces(char *split);
void	check_command(char *line, char **env);
/*
** FREE
*/
void	free_array(char **tab);

#endif
