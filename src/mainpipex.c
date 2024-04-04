/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:36:52 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/04 15:06:39 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main (int ac, char **av, char **env)
{
	pid_t	pid;
	//char	*av[] = {"/bin/sh", "-c", "ls -l", NULL};
	char *ad[3] = {av[2], av[3], NULL};
	pid = fork();
	if (pid == 0)
		execve(av[2], ad, env);
	else if (pid > 0)
		wait(NULL);
	else
		ft_printf("fork() failed!\n");
	return 0;
}
