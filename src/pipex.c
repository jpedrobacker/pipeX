/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:18 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/11 12:43:37 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	*process2(t_data *data)
{
	char	**cmd;
	char	*path;

	close(data->pd[1]);
	data->outfile = open(data->av[4], O_CREAT | O_RDONLY | O_WRONLY, 0777);
	if (data->outfile == -1)
	{
		close(data->pd[0]);
		return(print_error("Error in outfile"), NULL);
	}
	if (dup2(data->outfile, 1) == -1)
		return (print_error("Error on dup2 process 2 outfile"), NULL);
	if (dup2(data->pd[0], 0) == -1)
	{
		close(data->outfile);
		close(data->pd[0]);
		return (print_error("Error on dup2 process 2 pd[0]"), NULL);
	}
	close(data->pd[0]);
	cmd = ft_split(data->av[3], ' ');
	path = env_path(cmd[0], data->envp);
	close(data->outfile);
	execve(path, cmd, data->envp);
	print_error("Error in execve process 2");
	return (to_free(cmd), free(path), path = NULL, NULL);
}

void	*process1(t_data *data)
{
	char	**cmd;
	char	*path;

	close(data->pd[0]);
	data->infile = open(data->av[1], O_RDONLY);
	if (data->infile == -1)
	{
		close(data->pd[1]);
		return (print_error("Error in open1()"), NULL);
	}
	if (dup2(data->infile, 0) == -1)
		return (print_error("Error in dup2()"), close(data->infile), NULL);
	if (dup2(data->pd[1], 1) == -1)
	{
		close(data->infile);
		close(data->pd[1]);
		return (print_error("Error in dup2()"), NULL);
	}
	close(data->pd[1]);
	cmd = ft_split(data->av[2], ' ');
	path = env_path(cmd[0], data->envp);
	close(data->infile);
	execve(path, cmd, data->envp);
	print_error("Error on execve");
	return (to_free(cmd), free(path), path = NULL, NULL);
}

void	pipex(t_data *data)
{
	pid_t	child;
	pid_t	parent;
	int		status;

	if (pipe(data->pd) == -1)
		print_error("Error! pipe()!");
	child = fork();
	if (child == -1)
		print_error("Error! fork1()!");
	if (child == 0)
		process1(data);
	parent = fork();
	if (parent == -1)
		print_error("Error! fork2()");
	if (parent == 0)
		process2(data);
}
