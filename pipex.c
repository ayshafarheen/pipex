/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:08:42 by afarheen          #+#    #+#             */
/*   Updated: 2023/03/15 10:16:30 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
The input function first opens the file to be read (infile) and then
splits the command to be applied using spaces to 'create' the argument list.
We then check if the absolute path or the relative path is sent. if
the absolute paths is set, we just duplicate the string or else we parse
the path in the parse_path function. If the command does not exist, we
throw an error. else we duplicate the input file's file descriptor to be
the standard input. and the write end of the pipe to be the standard output.
We then close all the open files and execute the required command.
*/
void	input(t_pipex *file_ele)
{
	char	*temp;
	int		fd1;

	fd1 = open(file_ele->argv[1], O_RDONLY);
	check_error_file(fd1, file_ele->argv[1], file_ele, fd1);
	check_empty(file_ele, 2, fd1);
	file_ele->args = ft_split(file_ele->argv[2], ' ');
	temp = file_ele->args[0];
	if (access(file_ele->args[0], X_OK) == 0)
		file_ele->args[0] = ft_strdup(file_ele->args[0]);
	else
		file_ele->args[0] = parse_path(file_ele, fd1);
	free(temp);
	command_error(file_ele, fd1, file_ele->argv[2], 0);
	dup2(fd1, 0);
	dup2(file_ele->fd[1], 1);
	close(file_ele->fd[0]);
	close(fd1);
	close(file_ele->fd[1]);
	check_error_1(execve(file_ele->args[0], file_ele->args, file_ele->env),
		": is a directory \n", file_ele, fd1);
}

/*
The output function works the same as the input function except that
the file is opened in create with truncate and write. Here, the
read end of the pipe is duplicated to be standard input and the file
to be written to is duplicated to be the output stream.
*/
void	output(t_pipex *file_ele)
{
	char	*temp;
	int		fd1;

	free(file_ele->args);
	fd1 = open(file_ele->argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0666);
	check_error_file(fd1, file_ele->argv[4], file_ele, fd1);
	check_empty(file_ele, 3, fd1);
	file_ele->args = ft_split(file_ele->argv[3], ' ');
	temp = file_ele->args[0];
	if (access(file_ele->args[0], X_OK) == 0)
		file_ele->args[0] = ft_strdup(file_ele->args[0]);
	else
		file_ele->args[0] = parse_path(file_ele, fd1);
	free(temp);
	command_error(file_ele, fd1, file_ele->argv[3], 0);
	dup2(fd1, 1);
	dup2(file_ele->fd[0], 0);
	close(file_ele->fd[0]);
	close(fd1);
	close(file_ele->fd[1]);
	check_error_1(execve(file_ele->args[0], file_ele->args, file_ele->env),
		": is a directory\n", file_ele, fd1);
}
