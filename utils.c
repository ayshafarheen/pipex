/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:22:33 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/07 18:35:33 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Just assigns the required variables in the struct.
*/
t_pipex	*alloc_assign(char **env, char **argv)
{
	t_pipex	*file_ele;

	file_ele = ft_calloc(1, sizeof(t_pipex));
	file_ele->env = env;
	file_ele->argv = argv;
	return (file_ele);
}

/*
closes the necessary file descriptors, waits for the necessary
process ids(the children) and then frees the required elements.
*/
void	wait_and_free(int pid1, int pid2, t_pipex *file_ele)
{
	close(file_ele->fd[0]);
	close(file_ele->fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(file_ele -> args);
	free(file_ele);
}
