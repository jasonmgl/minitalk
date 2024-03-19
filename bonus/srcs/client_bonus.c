/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:53:13 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/23 10:57:03 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 7;

static void	ft_exit(char *str)
{
	ft_putstr_fd("\e[31mError\n\e[0m", 2);
	if (str)
		ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	ft_recept(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\e[32m[Message received]\n\e[0m");
		exit(EXIT_SUCCESS);
	}
}

static void	send_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (g_bit >= 0)
		{
			if (((unsigned char)str[i] >> g_bit & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_exit("SIGUSR1");
			}
			else if (((unsigned char)str[i] >> g_bit & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_exit("SIGUSR2");
			}
			g_bit--;
			usleep(80);
		}
		i++;
		g_bit = 7;
	}
}

static void	client(int pid, char *str)
{
	int					i;
	struct sigaction	s_sig;

	i = 0;
	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = &ft_recept;
	sigaction(SIGUSR1, &s_sig, NULL);
	send_msg(str, pid);
	i = INT_MIN;
	while (g_bit >= 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_exit("SIGUSR1");
		g_bit--;
		usleep(80);
	}
	while (i != INT_MAX)
		i++;
	ft_exit("\e[31m[Message not received]\e[0m");
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		client(atoi(argv[1]), argv[2]);
	return (0);
}
