/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:53:13 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/23 10:53:26 by jmougel          ###   ########.fr       */
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
	send_msg(str, pid);
	while (g_bit >= 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_exit("SIGUSR1");
		g_bit--;
		usleep(80);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		client(atoi(argv[1]), argv[2]);
	return (0);
}
