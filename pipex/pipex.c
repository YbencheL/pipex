/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:14 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/14 16:53:57 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(char **argv, int *fd1, int *fd2)
{
	*fd1 = open(argv[1], O_RDONLY);
	if (*fd1 == -1)
	{
		perror("Error opening input file");
		exit(1);
	}
	*fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (*fd2 == -1)
	{
		perror("Error opening output file");
		exit(1);
	}
}

void	child_process(char **argv, int *pipefd, char **env)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening input file");
		exit(1);
	}
	close(pipefd[0]);
	execute_command(argv[2], fd1, pipefd[1], env);
}

void	parent_process(char **argv, int *pipefd, char **env)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 == -1)
	{
		perror("Error opening output file");
		exit(1);
	}
	close(pipefd[1]);
	execute_command(argv[3], pipefd[0], fd2, env);
}

void	create_pipe_and_fork(char **argv, int *pipefd, char **env)
{
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("Error in pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, pipefd, env);
	else
		parent_process(argv, pipefd, env);
}

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];

	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		return (1);
	}
	validate_files(argv[1]);
	create_pipe_and_fork(argv, pipefd, env);
	return (0);
}
