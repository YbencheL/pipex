/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:14 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/17 12:39:14 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *pipefd, char **env)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		exit(1);
	}
	close(pipefd[0]);
	execute_command(argv[2], fd1, pipefd[1], env);
	close(fd1);
	exit(0);
}

void	parent_process(char **argv, int *pipefd, char **env)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 == -1)
	{
		ft_printf("Error opening output file: %s\n", strerror(errno));
		exit(1);
	}
	close(pipefd[1]);
	execute_command(argv[3], pipefd[0], fd2, env);
	close(fd2);
	exit(0);
}

void	create_pipe_and_fork(char **argv, int *pipefd, char **env)
{
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
	{
		ft_printf("Error in pipe\n");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("Error in fork\n");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, pipefd, env);
	else
	{
		parent_process(argv, pipefd, env);
		waitpid(pid, &status, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];

	if (argc != 5)
	{
		ft_printf("Use like this: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	if (access(argv[1], F_OK | R_OK) != 0)
		ft_printf("Error: %s: %s\n", strerror(errno), argv[1]);
	create_pipe_and_fork(argv, pipefd, env);
	return (0);
}
