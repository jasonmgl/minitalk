/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:36:30 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:25:56 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*lstlast;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstlast = ft_lstlast(*lst);
	lstlast->next = new;
}

/*
** static void		ft_print_lst(t_list *lst)
** {
** 	while (lst)
** 	{
** 		printf("\n%s\n", (char *)lst->content);
** 		lst = lst->next;
** 	}
** }
** 
** int		main(void)
** {
** 	t_list		*lst;
** 
** 	lst = ft_lstnew(ft_strdup("test1"));
** 	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("test2")));
** 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("test3")));
** 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("test4")));
** 	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("test5")));
** 	ft_print_lst(lst);
** 	return (0);
** }
*/