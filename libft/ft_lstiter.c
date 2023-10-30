/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:42:18 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/21 18:43:09 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
applies a function passed to all the elements in a list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur_node;

	cur_node = lst;
	while (cur_node)
	{
		(*f)(cur_node -> content);
		cur_node = cur_node ->next;
	}
}
