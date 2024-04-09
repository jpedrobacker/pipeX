/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:18 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/08 22:46:20 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	process2(t_data *data)
{
	char	**cmd;
	char	*path;
}

void	process1(t_data *data)
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
	//fazer o split do comando + flags e jogo no cmd
	//parte aonde faço a checagem de path, executo os comandos com execve()
	//lembrar de dar close nos arquivos
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
