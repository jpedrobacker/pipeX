/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:13 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/18 11:08:05 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmds_pth;
	char	**cmds_arg;
	char	*cmd;
	char	*path;
	int		infile;
	int		outfile;
	int		pd[2];
}	t_data;

char	*find_path(char **envp);
char	**cmd_split(char *cmd);
char	*get_cmd(char **path, char *cmd);
void	print_error(char *str);
void	perror_print(char *str);
void	to_free_parent(t_data *data);
void	to_free_child(t_data *data);
void	process1(t_data data, char **av, char **envp);
void	process2(t_data data, char **av, char **envp);
int		parent2(t_data *data);

#endif
