/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:48:06 by afarheen          #+#    #+#             */
/*   Updated: 2022/12/11 12:00:37 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check(char **new)
{
	char	*check;
	char	*temp;

	if (ft_strchr(*new, '\n') != 0)
	{
		check = ft_strchr(*new, '\n');
		temp = *new;
		if (*(check + 1) == 0)
			*new = NULL;
		else
			*new = ft_strdup(check + 1);
		*(check + 1) = 0;
		return (temp);
	}
	else
		return (NULL);
}

char	*line(char **new, char *str, int fd)
{
	char	*temp;
	char	*new_line_check;
	int		chars_read;

	chars_read = 1;
	while (chars_read > 0)
	{
		new_line_check = check(new);
		if (new_line_check)
			return (new_line_check);
		chars_read = read(fd, str, BUFFER_SIZE);
		if (chars_read <= 0)
			break ;
		if (!*new)
			*new = ft_strdup("");
		str[chars_read] = '\0';
		temp = *new;
		*new = ft_strjoin(*new, str);
		free(temp);
	}
	temp = *new;
	*new = NULL;
	return (temp);
}

/*
create a 2d array that can hold upto 1024 instances and assign
the stashes according to the index (use file descripter as index)
*/
char	*get_next_line(int fd)
{
	char		*str;
	static char	*new[1024];
	char		*return_val;
	size_t		buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (size_t)BUFFER_SIZE;
	str = malloc(buffer + 1);
	if (!str)
		return (0);
	return_val = line(&new[fd], str, fd);
	free(str);
	return (return_val);
}
