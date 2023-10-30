/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:51:59 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 16:48:03 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
applies a function to all the elements in a list and creates a new
list out of these results. if the function return was null, delete
the node, otherwise add the node to the back.
finally returns the first element of the new list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev_cur;
	t_list	*start;
	t_list	*temp;

	if (!lst || !*f || !*del)
		return (0);
	prev_cur = lst;
	temp = (*f)(prev_cur -> content);
	start = ft_lstnew(temp);
	while (prev_cur -> next)
	{
		prev_cur = prev_cur -> next;
		temp = ft_lstnew((*f)(prev_cur -> content));
		if (!temp)
			ft_lstdelone(temp, (*del));
		else
			ft_lstadd_back(&start, temp);
	}
	return (start);
}
