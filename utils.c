/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:23:30 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/21 20:37:36 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*find_command_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*command_path;
	int		i;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	paths = ft_split(*env + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(path, cmd);
		free(path);
		if (access(command_path, X_OK) == 0)
		{
			ft_free_path(paths);
			return (command_path);
		}
		free(command_path);
	}
	ft_free_path(paths);
	return (NULL);
}

void	print_error(char *msg, char *cmd)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, ": ", 2);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	execute_command(char *cmd, int input_f, int output_f, char **env)
{
	char	*command_path;
	char	**command;

	command = ft_split(cmd, ' ');
	if (access(command[0], X_OK) == 0)
		command_path = command[0];
	else
		command_path = find_command_path(command[0], env);
	if (!command_path)
	{
		print_error(strerror(errno), command[0]);
		ft_free_path(command);
		exit(1);
	}
	dup2(input_f, 0);
	dup2(output_f, 1);
	close(input_f);
	close(output_f);
	execve(command_path, command, env);
	print_error("Error in execve", strerror(errno));
	if (command_path != command[0])
		free(command_path);
	ft_free_path(command);
	exit(1);
}
