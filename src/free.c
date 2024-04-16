/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:18:21 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/16 13:03:20 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	to_free_parent(t_data *data)
{
	int	i;

	i = 0;
	close(data->infile);
	close(data->outfile);
	while (data->cmds_pth[i])
	{
		free(data->cmds_pth[i]);
		i++;
	}
	free(data->cmds_pth);
}

void	to_free_child(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds_arg[i])
	{
		free(data->cmds_arg[i]);
		i++;
	}
	free(data->cmds_arg);
	free(data->cmd);
}
