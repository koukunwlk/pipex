/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:05:56 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/02 13:30:59 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_infile;
	int	fd_outfile;

	if(argc == 5)
	{
		fd_infile = openfile(argv[1], INFILE);
		fd_outfile = openfile(argv[4], OUTFILE);
	}
	return (0);
}

int	openfile(char *filename, int mode)
{
	if(mode == INFILE)
	{
		if(access(filename, F_OK))
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
