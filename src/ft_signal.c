
#include "../includes/minishell.h"

void	simple_handler(int signal_nb)
{
	if (signal_nb == SIGINT)
	{
		ft_putstr("\n");
		ft_printf("{r}$>{R}");
		signal(SIGINT, simple_handler);
	}
}

void	program_handler(int signal_nb)
{
	if (signal_nb == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, program_handler);
	}
}
