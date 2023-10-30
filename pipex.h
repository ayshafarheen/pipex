/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:24:55 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/07 18:12:04 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	char	**env;
	char	**argv;
	char	**args;
}	t_pipex;

char	*ft_strcpy(char *dest, char *src);
char	*parse_path(t_pipex *file_ele, int fd1);
void	check_error_1(int n, char *error, t_pipex *file_ele, int fd1);
void	check_error_file(int n, char *error, t_pipex *file_ele, int fd1);
char	*create_path(char *arg1, char *paths, char **final);
void	output(t_pipex *file_ele);
void	input(t_pipex *file_ele);
t_pipex	*alloc_assign(char **env, char **argv);
void	wait_and_free(int pid1, int pid2, t_pipex *file_ele);
void	check_empty(t_pipex *file_ele, int index, int fd1);
void	command_error(t_pipex *file_ele, int fd1, char *command, int flag);
char	*parse_path(t_pipex *file_ele, int fd);

#endif
