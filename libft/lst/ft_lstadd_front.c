/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:33:15 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:25:58 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
** void	disp_list(t_list *lst)
** {
** 	size_t	i;
** 
** 	if (lst == NULL)
** 	{
** 		printf("The list is empty\n");
** 		return ;
** 	}
** 	i = 0;
** 	while (lst)
** 	{
** 		printf("NODE %zu : \"%s\"\n", i, (char *)lst->content);
** 		lst = lst->next;
** 		i++;
** 	}
** }
** 
** int		main(void)
** {
** 	t_list	*lst;
** 	t_list	*node;
** 	lst = NULL;
** 	disp_list(lst);
** 	node = ft_lstnew(ft_strdup("test"));
** 	ft_lstadd_front(&lst, NULL);
** 	disp_list(lst);
** 
** 	node = ft_lstnew(ft_strdup("test2"));
** 	ft_lstadd_front(&lst, NULL);
** 	disp_list(lst);
** 	return (0);
** }
*/