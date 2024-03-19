/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:28:40 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/23 10:29:01 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define END	"\e[0m"

# include <unistd.h>
# include "libft.h"
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>

void	server(int signal, siginfo_t *pid, void *ptr);
void	ft_recept(int signal);

#endif