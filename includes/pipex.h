/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:18:43 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/02 19:35:55 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define INFILE 0
# define OUTFILE 1

/* Struct */
typedef struct s_pipe {
	int		fd[2];
	int		infile;
	int		outfile;
	char	**args_cmd;
	char	*path;
	pid_t	p_child;
}	t_pipe;

/* Libft functions */
char	*ft_strdup(char *str, unsigned int n);
char	**ft_split(char *str, char sep);
int		ft_strchr(char *str, char c);
int		ft_strncmp(char *str1, char *str2, int n);

/* Pipex functions */
void	openfile(char *filename, int mode, t_pipe *pipex);
void	exec_cmd(char *cmd, char **envp, t_pipe *pipex);
void	redirect(char *cmd, char **envp, t_pipe *pipex);

/* utils */
char	*path_join(char *path, char *cmd);
char	*get_path(char *cmd, char **envp);
void 	free_args(char **ptr);

#endif
