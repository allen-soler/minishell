/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:43 by jallen            #+#    #+#             */
/*   Updated: 2019/02/09 14:17:45 by jallen           ###   ########.fr       */
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
int		ft_setenv(char *name, char *new_val, char **env);
char	*ft_getenv(char **env, char *src);
/*
** Bins
*/
void	ft_binary(char **argv, char **env);
void	ft_local_binary(char **argv);
/*
**	Pick bins
*/
int		pick_binary(char *line);
void	choose_binary(char *line, char **env, int nb);
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
void	ft_checking_av(char **av, char **env);
int		remove_spaces(char *split);
/*
** FREE
*/
void	free_array(char **tab);

#endif
