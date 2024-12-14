/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:23:30 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/14 16:53:28 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_files(char *file1)
{
	if (access(file1, F_OK | R_OK) != 0)
	{
		perror("Error: Cannot access input file");
		exit(1);
	}
}

void	execute_command(char *cmd, int input_fd, int output_fd, char **env)
{
	char	command_path[256];
	char	**command;

	ft_strlcpy(command_path, "/usr/bin/", sizeof(command_path));
	ft_strlcat(command_path, cmd, sizeof(command_path));
	command = ft_split(command_path, ' ');
	if (input_fd != -1)
		dup2(input_fd, 0);
	if (output_fd != -1)
		dup2(output_fd, 1);
	close(input_fd);
	close(output_fd);
	execve(command[0], command, env);
	perror("Error in execve");
	exit(1);
}
