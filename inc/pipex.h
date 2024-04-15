/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:13 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/15 19:42:49 by jbergfel         ###   ########.fr       */
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
	char	**envp;
	char	**av;
	char	**cmds_pth;
	char	**cmds_arg;
	char	*cmd;
	char	*path;
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		pd[2];
}	t_data;

char	*find_path(char **envp);
char	**cmd_split(char *cmd);
char	*get_cmd(char **path, char *cmd);
void	print_error(char *str);
void	to_free_parent(t_data *data);
void	to_free_child(t_data *data);
void	process1(t_data data, char **av, char **envp);
void	process2(t_data data, char **av, char **envp);
int		parent2(t_data *data);

#endif
