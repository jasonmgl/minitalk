/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:53:55 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/23 10:55:12 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 7;

static void	ft_exit_fail(char *str)
{
	ft_putstr_fd("\e[31mError\n\e[0m", 2);
	if (str)
		ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static void	ft_exit_succ(unsigned char **str)
{
	if (*str)
		free(*str);
	exit(EXIT_SUCCESS);
}

static void	display_msg(unsigned char **str)
{
	g_bit = 7;
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
}

void	server(int signal, siginfo_t *pid, void *ptr)
{
	static unsigned char	c = 0;
	static unsigned char	*str = NULL;
	unsigned char			*tmp;

	(void)ptr;
	(void)pid;
	if (signal == SIGINT)
		ft_exit_succ(&str);
	if (signal == SIGUSR2)
		c = c + (1 << g_bit);
	g_bit--;
	if (str == NULL)
		str = (unsigned char *)ft_strdup("");
	if (str == NULL)
		return ;
	if (g_bit == -1)
	{
		if (c == 0)
			display_msg(&str);
		tmp = str;
		str = (unsigned char *)ft_strjoin((char *)str, (char *)&c);
		free(tmp);
		c = 0;
		g_bit = 7;
	}
}

int	main(void)
{
	struct sigaction	s_sig;
	int					pid;

	pid = getpid();
	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_sigaction = &server;
	ft_printf("\e[32m[PID] %d\n\e[0m", pid);
	if (sigaction(SIGUSR1, &s_sig, NULL) == -1)
		ft_exit_fail("SIGUSR1");
	if (sigaction(SIGUSR2, &s_sig, NULL) == -1)
		ft_exit_fail("SIGUSR2");
	if (sigaction(SIGINT, &s_sig, NULL) == -1)
		ft_exit_fail("SIGINT");
	while (1)
		continue ;
}
