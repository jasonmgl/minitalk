/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:19:48 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:16 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return ((int)i);
}

/*
** int		main(void)
** {
** 	t_list		*lst;
** 
** 	lst = ft_lstnew(ft_strdup("test1"));
** 	lst->next = ft_lstnew(ft_strdup("test2"));
** 	lst->next->next = ft_lstnew(ft_strdup("test3"));
** 	lst->next->next->next = ft_lstnew(ft_strdup("test4"));
** 	printf("\n%d\n", ft_lstsize(NULL));
** 	return (0);
** }
*/