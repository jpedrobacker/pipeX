/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:36:52 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/18 10:44:08 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parent2(t_data *data)
{
	int	status1;
	int	status2;
	int	error_code;

	error_code = 0;
	waitpid(data->pid1, &status1, 0);
	waitpid(data->pid2, &status2, 0);
	if (WIFEXITED(status1))
		error_code = WEXITSTATUS(status1);
	ft_printf("status 1: %i\n", error_code);
	if (WIFEXITED(status2))
		error_code = WEXITSTATUS(status2);
	ft_printf("status 2: %i\n", error_code);
	return (error_code);
}

void	close_data(t_data *data)
{
	close(data->pd[0]);
	close(data->pd[1]);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		error;

	if (ac != 5)
		print_error("Invalid arguments\n");
	data.infile = open(av[1], O_RDONLY);
	if (data.infile < 0)
		perror_print("Invalid infile\n");
	data.outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data.outfile < 0)
		perror_print("Invalid outfile\n");
	if (pipe(data.pd) < 0)
		perror_print("Invalid pipe\n");
	data.path = find_path(envp);
	data.cmds_pth = ft_split(data.path, ':');
	data.pid1 = fork();
	if (data.pid1 == 0)
		process1(data, av, envp);
	data.pid2 = fork();
	if (data.pid2 == 0)
		process2(data, av, envp);
	close_data(&data);
	error = parent2(&data);
	to_free_parent(&data);
	return (0);
}
