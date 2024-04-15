/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:47 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/15 19:28:26 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char **envp)
{
	while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp == NULL)
		print_error("Error find path\n");
	return (*envp + 5);
}

char	**cmd_split(char *cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			j = i + 1;
			while (cmd[j] != cmd[i] && cmd[j])
				j++;
			if (cmd[j])
			{
				cmd[i] = 26;
				cmd[j] = 26;
				i = j;
			}
		}
		else if (cmd[i] == ' ')
			cmd[i] = 26;
		i++;
	}
	return (ft_split(cmd, 26));
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		if (access(cmd, 0) == 0)
			return (cmd);
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
