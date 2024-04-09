/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:03:47 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/05 19:08:07 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*env_path(char **env)
{
	char	*env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = env[i];
			break ;
		}
		i++;
	}
	return (env_path);
}
