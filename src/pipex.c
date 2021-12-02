/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:05:56 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/02 14:16:18 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_infile;
	int	fd_outfile;

	if (argc == 5)
	{
		fd_infile = openfile(argv[1], INFILE);
		fd_outfile = openfile(argv[4], OUTFILE);
		dup2(fd_infile, STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
	}
	return (0);
}

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, "pipex: ", 7);
			write(STDERR_FILENO, filename, ft_strchr(filename, 0));
			write(STDERR_FILENO, " No such file or directory\n", 27);
			return (STDIN_FILENO);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666));
}

void	redirect(char *cmd, char **env, int fd_infile)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd)
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd(1), STDIN_FILENO);
		if (fd_infile == STDIN_FILENO)
		{
			exit (1);
		}
		else
			exec_cmd(cmd, env);
	}
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if(ft_strchr(args[0]. '/') > -1)
		path = args[0];
	else
		path = get_path(cmd, envp);
}

char	*get_path(char *cmd, char **envp);
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;


	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if(!envp[i])
		return (cmd);
	path = envp[i] + 5;
	while(path && ft_strchr(path, ':') > -1)
	{
		dir = ft_strdup(path, ft_strchr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if(access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr(path, ':') + 1;
	}
	return (cmd);
}
