/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:43 by jallen            #+#    #+#             */
/*   Updated: 2019/02/11 19:12:18 by jallen           ###   ########.fr       */
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
char	**malloc_env(char **env);
char	**ft_unset_env(char **name, char **env);
/*
** Bins
*/
void	ft_binary(char **av, char **env);
void	ft_local_binary(char **av, char **env);
/*
** Builtins
*/
void	ft_cd(char **av, char **env);
void	ft_echo(char *av, char **env);
int		check_builtins(char *av);
void	picking_builtins(char **av, char *line, char **env);
/*
** Parsing
*/
void	ft_checking_av(char **av, char **env);
void	ft_checking_var(char **av, char **env);
int		remove_spaces(char *split);
char	**ft_split(char const *str, char split);

#endif
