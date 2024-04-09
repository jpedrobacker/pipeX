/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:18:21 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/08 13:25:51 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	print_error(char *str)
{
	ft_printf("%s\n", str);
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
