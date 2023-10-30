/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:16:48 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 16:40:49 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
clears all the elements in a list that starts from the double pointer
that was passed. keep deleting all the elements using the ft_lstdelone()
and finally set the first pointer as NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_node;
	t_list	*temp;

	if (!lst || !*del)
		return ;
	cur_node = *lst;
	while (cur_node -> next)
	{
		temp = cur_node ->next;
		ft_lstdelone(cur_node, (*del));
		cur_node = temp;
	}
	ft_lstdelone(cur_node, (*del));
	*lst = NULL;
}
