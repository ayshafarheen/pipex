/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:10:52 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/07 18:11:04 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
takes in env and the required argument. It then loops through all the elements
in the PATH variable and separate them into the different possible paths where
the command could exist. this is then passed to the create_path() where the
final path is determined.
*/
char	*parse_path(t_pipex *file_ele, int fd)
{
	char	*paths;
	char	**final;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (file_ele->env[i])
	{
		paths = ft_strnstr(file_ele->env[i++], "PATH", 4);
		if (paths)
		{
			paths = ft_strnstr(file_ele->env[--i], "/", 10);
			flag = 1;
			break ;
		}
	}
	if (!flag)
		command_error(file_ele, fd, file_ele->args[0], -1);
	final = ft_split(paths, ':');
	i = 0;
	paths = create_path(file_ele->args[0], paths, final);
	free(final);
	return (paths);
}

/*
takes in the command as well as the list of all the paths and the path
variable(just for storage).
We iterate through all the paths and then concatenate the path with
the command passed. The accessibility is checked. The existence of the command
is determined by whether or not there is an access. if it exists return the
concatenated path or else NULL.
*/
char	*create_path(char *arg1, char *paths, char **final)
{
	char	*path2;
	int		i;

	i = 0;
	while (final[i])
	{
		path2 = ft_strjoin(final[i], "/");
		paths = ft_strjoin(path2, arg1);
		free(path2);
		if (access(paths, X_OK) == 0)
		{
			while (final[i])
				free(final[i++]);
			return (paths);
		}
		free(final[i++]);
		free(paths);
	}
	return (0);
}
