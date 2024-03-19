/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:40:39 by jmougel           #+#    #+#             */
/*   Updated: 2024/01/30 11:26:11 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*lst_new;
	t_list		*lst_temp;
	void		*tmp_content;

	lst_new = NULL;
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		tmp_content = (*f)(lst->content);
		lst_temp = ft_lstnew(tmp_content);
		if (!lst_temp)
		{
			del(tmp_content);
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, lst_temp);
		lst = lst->next;
	}
	return (lst_new);
}

/*
** static void		del(void *content)
** {
** 	content = NULL;
** 	free(content);
** }
** 
** static void    *f(void  *content)
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
** 	return (content);
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
** 	lst = ft_lstmap(lst, &f, &del);
** 	print_lst(lst);
** 	return (0);
** }
*/