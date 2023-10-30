/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:00:04 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/14 13:39:29 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_error(t_pipex *file_ele, int fd1, char *command, int flag)
{
	if (flag == -1 || file_ele->args[0] == 0)
	{
		write(2, command, ft_strlen(command));
		check_error_1(-1, ": Command not found\n", file_ele, fd1);
	}
}

void	check_empty(t_pipex *file_ele, int index, int fd1)
{
	char	*to_check;

	to_check = ft_strtrim(file_ele->argv[index], " ");
	if (ft_strcmp(to_check, "") == 0)
	{
		free(to_check);
		write(2, file_ele->argv[index], ft_strlen(file_ele->argv[index]));
		check_error_1(-1, ": Command not found\n", file_ele, fd1);
	}
	free(to_check);
}

/*
if there exists an error, print the error, close the necessary
file descriptors and then free the required elements.
*/
void	check_error_1(int n, char *error, t_pipex *file_ele, int fd1)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		write(2, error, ft_strlen(error));
		close(file_ele->fd[0]);
		close(file_ele->fd[1]);
		if (fd1 != -1)
			close(fd1);
		while (file_ele->args)
		{
			if (file_ele->args[i])
				free(file_ele->args[i++]);
			else if (i == 0)
				i++;
			else
				break ;
		}
		free(file_ele->args);
		free(file_ele);
		exit (0);
	}
}

/*
if there exists an error, print the error, close the necessary
file descriptors and then free the required elements.
*/
void	check_error_file(int n, char *error, t_pipex *file_ele, int fd1)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		perror(error);
		close(file_ele->fd[0]);
		close(file_ele->fd[1]);
		if (fd1 != -1)
			close(fd1);
		while (file_ele->args)
		{
			if (file_ele->args[i])
				free(file_ele->args[i++]);
			else if (i == 0)
				i++;
			else
				break ;
		}
		free(file_ele->args);
		free(file_ele);
		exit (0);
	}
}
