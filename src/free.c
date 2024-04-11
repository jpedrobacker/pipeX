/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:18:21 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/11 12:19:36 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	print_error(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	exit(1);
}

void	to_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
	{
		free(res[i]);
		res[i] = NULL;
	}
	free(res);
	res = NULL;
}
