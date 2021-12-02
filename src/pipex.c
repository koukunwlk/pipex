/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:05:56 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/02 11:35:16 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void init_pipe(t_pipe *pipex)
{
	pipex->infile = 0;
	pipex->outfile = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	pipex;
	int		infile = open(argv[2], O_RDONLY);
	int		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666)
	char	**cmd1;
	char	**cmd2;
	return (0);
}
