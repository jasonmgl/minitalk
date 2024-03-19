/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:37:20 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:03 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*
** static void		del(void *content)
** {
** 	free(content);
** 	content = NULL;
** }
** 
** static void		ft_print_lst(t_list *lst)
** {
** 	if (!lst)
** 	{
** 		printf("\nList empty\n");
** 		return ;
** 	}
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
** 	lst = NULL;
** 	ft_print_lst(lst);
** 	lst = ft_lstnew(ft_strdup("test1"));
** 	ft_print_lst(lst);
** 	ft_lstdelone(lst, &del);
** 	ft_print_lst(lst);
** 	return (0);
** }
*/