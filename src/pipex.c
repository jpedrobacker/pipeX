/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:18 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/16 12:45:56 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	process1(t_data data, char **av, char **envp)
{
	dup2(data.pd[1], 1);
	close(data.pd[0]);
	dup2(data.infile, 0);
	data.cmds_arg = cmd_split(av[2]);
	data.cmd = get_cmd(data.cmds_pth, data.cmds_arg[0]);
	if (!data.cmd)
	{
		to_free_child(&data);
		to_free_parent(&data);
		ft_putstr_fd("Error pipex\n", 2);
		exit(127);
	}
	if (execve(data.cmd, data.cmds_arg, envp) == -1)
		exit(1);
	exit(0);
}

void	process2(t_data data, char **av, char **envp)
{
	dup2(data.pd[0], 0);
	close(data.pd[1]);
	dup2(data.outfile, 1);
	data.cmds_arg = cmd_split(av[3]);
	data.cmd = get_cmd(data.cmds_pth, data.cmds_arg[0]);
	if (!data.cmd)
	{
		to_free_child(&data);
		to_free_parent(&data);
		ft_putstr_fd("Error pipex\n", 2);
		exit(127);
	}
	if (execve(data.cmd, data.cmds_arg, envp) == -1)
		exit(1);
	exit(0);
}
