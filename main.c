/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:51 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/12 12:49:21 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
First checks for the right number of arguments.
It then allocates the structure (contains the variables that are required
thorughout the program). We first build the pipe and then fork to create
the child for the first command. we then go to the input() function to
implement the first part of the pipe. We then fork again to create the
second process for the second command. we then go to the output() function
to implement the second part of the pipe. Finally we close all the required
file descriptors, wait for the chidren and then free the required vars.
*/
int	main(int argc, char **argv, char **env)
{
	t_pipex	*file_ele;
	int		pid1;
	int		pid2;

	if (argc == 5)
	{
		file_ele = alloc_assign(env, argv);
		check_error_1(pipe(file_ele->fd), "Pipe error\n", file_ele, -1);
		pid1 = fork();
		check_error_1(pid1, "Forking error\n", file_ele, -1);
		if (pid1 == 0)
			input(file_ele);
		pid2 = fork();
		check_error_1(pid2, "Forking error\n", file_ele, -1);
		if (pid2 == 0)
			output(file_ele);
		wait_and_free(pid1, pid2, file_ele);
	}
	else
		write(2, "Wrong number of arguments\n", 26);
	return (0);
}
