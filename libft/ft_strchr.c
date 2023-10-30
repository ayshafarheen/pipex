/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:41:12 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:27:42 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checks for the character equivalent of the int passed in the
string and returns the string from that position if it is found.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen((char *)s))
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
