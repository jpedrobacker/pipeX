/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:13 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/11 11:50:34 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**envp;
	char	**av;
	char	*cmd1;
	char	*cmd2;
	int		infile;
	int		outfile;
	int		pd[2];
}	t_data;

char	*env_path(char *cmd, char **env);
char	**get_path(char **envp);
void	print_error(char *str);
void	to_free(char **res);
void	pipex(t_data *data);
void	*process1(t_data *data);
void	*process2(t_data *data);

#endif
