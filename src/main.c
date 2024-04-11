/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:36:52 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/11 12:17:09 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int ac, char **av, char **envp)
{
	t_data	data;

	if (!envp)
		print_error("Error! No envp provided!");
	if (ac != 5)
		print_error("Error! Not enough args!");
	data.envp = envp;
	data.av = av;
	pipex(&data);
	return (0);
}

