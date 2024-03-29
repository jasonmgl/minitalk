/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:27 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:00 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;

	tmp = NULL;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/*
** static void		del(void *content)
** {
** 	content = NULL;
** 	free(content);
** }
** 
** static void		print_lst(t_list *lst)
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
** 	lst = ft_lstnew(ft_strdup("hello"));
** 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
** 	print_lst(lst);
** 	ft_lstclear(&lst, &del);
** 	print_lst(lst);
** 	return (0);
** }
*/