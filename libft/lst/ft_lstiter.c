/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:39:21 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:06 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
** void    f(void  *content)
** {
** 	char	ptr[5] = "okteo";
** 
** 	int	i = 0;
** 	while (i < 4)
** 	{
** 		((char *)content)[i] = ptr[i];
** 		i++;
** 	}
** 	((char *)content)[i] = '\0';
** }
** 
** static void		print_lst(t_list *lst)
** {
** 	while (lst)
** 	{
** 		printf("\n%s", (char *)lst->content);
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
** 	ft_lstiter(lst, &f);
** 	print_lst(lst);
** 	return (0);
** }
*/