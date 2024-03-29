/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:22:55 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/01 13:53:46 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_verifn_gnl(char	*stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_error_gnl(char **buf, char **stash)
{
	if (!*buf && *stash)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	else if (!*stash && *buf)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	else if (!*buf && !*stash)
		return (NULL);
	else
	{
		free(*buf);
		*buf = NULL;
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*buf;
	char			*next_line;
	static ssize_t	len_read = 0;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || fd == -1 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (ft_error_gnl(&buf, &stash));
	while (!ft_verifn_gnl(stash))
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		if (len_read == -1)
			return (ft_error_gnl(&buf, &stash));
		buf[len_read] = '\0';
		stash = ft_strjoin_gnl(buf, stash);
		if (len_read == 0)
			break ;
	}
	if (len_read == 0 && stash[0] == '\0')
		return (ft_error_gnl(&buf, &stash));
	free(buf);
	next_line = ft_extract_line_gnl(stash);
	stash = ft_rebuild_stash_gnl(stash);
	return (next_line);
}
