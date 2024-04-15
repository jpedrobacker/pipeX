/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:36:52 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/15 19:44:24 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_data data)
{

}

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
	printf("status 1: %i\n", error_code);
	if (WIFEXITED(status2))
		error_code = WEXITSTATUS(status2);
	printf("status 2: %i\n", error_code);
	return (error_code);
}

int main(int ac, char **av, char **envp)
{
	t_data	data;
	int		error;

	if (ac != 5)
		print_error("Invalid args\n");
	data.infile = open(av[1], O_RDONLY);
	if (data.infile < 0)
		print_error("Invalid infile\n");
	data.outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data.outfile < 0)
		print_error("Invalid outfile\n");
	if (pipe(data.pd) < 0)
		print_error("Invalid pipe\n");
	data.path = find_path(envp);
	data.cmds_pth = ft_split(data.path, ':');
	data.pid1 = fork();
	if (data.pid1 == 0)
		process1(data, av, envp);
	data.pid2 = fork();
	if (data.pid2 == 0)
		process2(data, av, envp);
	close(data.pd[0]);
	close(data.pd[1]);
	error = parent2(&data);
	to_free_parent(&data);
	return (0);
}
