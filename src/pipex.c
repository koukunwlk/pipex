/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:05:56 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/03 16:48:47 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc == 5)
	{
		openfile(argv[1], INFILE, &pipex);
		openfile(argv[4], OUTFILE, &pipex);
		dup2(pipex.infile, STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		redirect(argv[2], envp, &pipex);
		exec_cmd(argv[3], envp, &pipex);
	}
	else if(argc > 5)
		write(STDOUT_FILENO, "To many arguments", 17);
	return (0);
}

void	openfile(char *filename, int mode, t_pipe *pipex)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, "pipex: ", 7);
			write(STDERR_FILENO, filename, ft_strchr(filename, 0));
			write(STDERR_FILENO, " No such file or directory\n", 27);
			exit(0);
		}
		pipex->infile = open(filename, O_RDONLY);
	}
	else
		pipex->outfile = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
}

void	redirect(char *cmd, char **envp, t_pipe *pipex)
{
	pipe(pipex->fd);
	pipex->p_child = fork();
	if (pipex->p_child == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
		if (pipex->infile == STDIN_FILENO)
		{
			exit (0);
		}
		else
			exec_cmd(cmd, envp, pipex);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
		waitpid(pipex->p_child, NULL, WNOHANG);
	}
}

void	exec_cmd(char *cmd, char **envp, t_pipe *pipex)
{
	if (ft_strncmp(cmd, "awk", 3) == 0)
	{
		pipex->args_cmd = ft_split(cmd, '\'');
		pipex->args_cmd[0][3] = 0;
	}
	else
		pipex->args_cmd = ft_split(cmd, ' ');
	if (ft_strchr(pipex->args_cmd[0], '/') > -1)
		pipex->path = pipex->args_cmd[0];
	else
		pipex->path = get_path(pipex->args_cmd[0], envp);
	if (access(pipex->path, F_OK))
	{
		free_pipex(pipex);
		write(STDERR_FILENO, "pipex: ", 7);
		write(STDERR_FILENO, cmd, ft_strchr(cmd, 0));
		write(STDERR_FILENO, ": command not found\n", 20);
		exit(1);
	}
	execve(pipex->path, pipex->args_cmd, envp);
}

char	*get_path(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i] + 5;
	while (path && ft_strchr(path, ':') > -1)
	{
		dir = ft_strdup(path, ft_strchr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr(path, ':') + 1;
	}
	return (cmd);
}
