/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:47 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/11 12:21:10 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**get_path(char **envp)
{
	char	**env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			env_path = ft_split(envp[i] + 5, ':');
			return(env_path);
		}
		i++;
	}
	return (NULL);
}

char	*env_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*c_path;
	int		i;

	if (access(cmd, F_OK | R_OK | X_OK) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "/", 1) == 0)
	{
		if (access(cmd, F_OK | R_OK | X_OK) == 0)
			return (cmd);
		else
			print_error("Error in cmd path");
	}
	all_paths = get_path(envp);
	i = -1;
	while (all_paths && all_paths[++i])
	{
		c_path = ft_strjoin(all_paths[i], "/");
		c_path = ft_strjoin(c_path, cmd);
		if (access(c_path, F_OK | R_OK | X_OK) == 0)
			return (c_path);
		free(c_path);
		c_path = NULL;
	}
}

