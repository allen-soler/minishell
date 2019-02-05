/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:58:43 by jallen            #+#    #+#             */
/*   Updated: 2019/02/05 15:27:07 by jallen           ###   ########.fr       */
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
