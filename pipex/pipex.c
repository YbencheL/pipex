/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:14 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/14 11:50:19 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    if (argc == 5)
    {
        char *file1 = argv[1];
        char *cmd1 = argv[2];
        char *cmd2 = argv[3];
        char *file2 = argv[4];
        int pipefd[2];
        pid_t pid;
        if ((access(file1, F_OK | R_OK) == 0) && (access(file2, F_OK | W_OK) == 0))
        {
            char command_path1[256] = "/usr/bin/";
            char command_path2[256] = "/usr/bin/";
            
            ft_strlcat(command_path1, cmd1, sizeof(command_path1));
            ft_strlcat(command_path2, cmd2, sizeof(command_path2));
            char **command1 = ft_split(command_path1, ' ');
            char **command2 = ft_split(command_path2, ' ');
            if (pipe(pipefd) == -1)
            {
                perror("error in pipe");
                return 1;
            }
            pid = fork();
            if (pid == -1)
            {
                perror("error in fork");
                return 1;
            }
            if (pid == 0)
            {
                int fd1 = open(file1, O_RDONLY);
                if (fd1 == -1)
                {
                    perror("error in open");
                    return 1;
                }
                dup2(fd1, 0);
                dup2(pipefd[1], 1);
                close(fd1);
                close(pipefd[1]);
                close(pipefd[0]);
                execve(command1[0], command1, env);
                perror("execve");
                return 1;
            }
            else
            {
                int fd2 = open(file2, O_WRONLY);
                if (fd2 == -1)
                {
                    perror("error in open");
                    return 1;
                }
                dup2(pipefd[0], 0);
                dup2(fd2, 1);
                close(fd2);
                close(pipefd[0]);
                close(pipefd[1]);
                execve(command2[0], command2, env);
                perror("execve");
                return 1;
            }
        }
        else
        {
            perror("fucking erro man");
            return 1;
        }
    }
    else
        return 0;
}