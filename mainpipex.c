/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:36:52 by jbergfel          #+#    #+#             */
/*   Updated: 2023/11/30 17:48:55 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char *av[])
{
	pid_t	child;
	pid_t	parent;
	int		status;

	child = fork();
	if (child == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		execlp(av[1], av[1], (char *)NULL);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}
	else
		parent = waitpid(child, &status, 0);
	if (parent == -1)
	{
		perror("Parent Failed");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		ft_printf("Child process exited with status %d\n", WEXITSTATUS(status));
	else
		ft_printf("Child process did not exit normally\n");
	return (0);
}