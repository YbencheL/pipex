// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
//     // if (access("readfile", R_OK) == 0)
//     //     printf("readfile is accessible in reading mode\n");
//     // if (access("writefile", W_OK) == 0)
//     //     printf("writefile is accessible in writing mode\n");
//     // if (access("executefile", X_OK) == 0)
//     //     printf("executefile is accessible in execution mode\n");
//     // if (access("readfile", R_OK|W_OK) == 0)
//     //     printf("readfile is accessible in writing and reading mode\n");
// }

// #include <unistd.h>
// #include <fcntl.h>

// int main(int ac, char *av[], char *env[])
// {
//     (void) ac;
//     (void) av;
//     int in;
//     int out;
//     char *grep_args[] = {"grep", "boujdour", NULL};
    
//     // open input and output files (assuming both files exist)
//     in = open("in", O_RDONLY);
//     out = open("out", O_WRONLY); 
    
//     // replace standard input with input file
//     dup2(in, 0);
//     dup2(out, 1);
//     // close unused file descriptors
//     close(in);
//     close(out);
    
//     // execute grep
//     execve("/usr/bin/grep", grep_args, NULL);
// }


// #include <sys/types.h>
// #include <unistd.h>
// #include <stdio.h>

// void main()
// {
//     int pipefds[2];
//     char buffer[256] = {0};
//     printf("parent pid: %d\n", getpid());
//     pipe(pipefds);
//     write(pipefds[1], "msg", 3);
//     if (fork() > 0) {
//         return;
//     }

//     read(pipefds[0], buffer, 3);

//     printf("got from pipe: %s\n", buffer);
//     printf("child pipe: %d\n", getpid());
// }


// #include <fcntl.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main(int ac, char *av[], char *env[])
// {
//     (void) ac;
//     (void) av;
//     int pipefd[2];
//     pid_t pid;
//     int status;
    
//     char *cat_args[] = {"/usr/bin/cat", "infile", NULL};
//     char *grep_args[] = {"/usr/bin/grep", "tony", NULL};
    
//     pipe(pipefd);
    
//     pid = fork();
     
//     if (pid == 0)
//     {

//         dup2(pipefd[0], STDIN_FILENO);
  
//         close(pipefd[1]);
        
//         execve("/usr/bin/grep", grep_args, env);
//     }
//     else
//     {
//         dup2(pipefd[1], STDOUT_FILENO);

//         close(pipefd[0]);
        
//         execve("/bin/cat", cat_args, env);
//     }
    
//     close(pipefd[0]);
//     close(pipefd[1]);
//     waitpid(pid, &status, 0);
    
//     return 0;
// }

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main(int arc, char *argv[])
// {
//     int fds[2];
//     int x, y;
//     pipe(fds);
//     int pid = fork();
//     if (pid == 0)
//     {
//         printf("inter number : ");
//         scanf("%d", &x);
//         write(fds[1], &x, sizeof(int));
//         close(fds[1]);
//     }else
//     {
//         read(fds[0], &y, sizeof(int));
//         printf("you number is : %d\n", y);
//         close(fds[0]);
//     }
//     return 0;
// }

/**
 * Executes the command "cat infile | grep Lausanne".  
 */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char *av[], char *env[])
{
    (void) ac;
    (void) av;
    int pipefd[2];
    pid_t pid;
    
    char *cat_args[] = {"/bin/cat", "infile", NULL};
    char *grep_args[] = {"/usr/bin/grep", "tony", NULL};
    
    // make a pipe
    // fds go in pipefd[0] and pipefd[1]
    pipe(pipefd);

    pid = fork();
    
    if (pid == 0)
    {
        // child process gets here and handles "grep Lausanne"
        // replace standard input with input part of the pipe
        dup2(pipefd[0], 0);
        
        close(pipefd[1]);

        execve("/usr/bin/grep", grep_args, env);
    }
    else
    {
        // parent process gets here and handles "cat scores"
        // replace standard output with output part of pipe
        dup2(pipefd[1], 1);
        
        close(pipefd[0]);

        execve("/bin/cat", cat_args, env);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    // wait for the child process to finish
    int status;
    waitpid(pid, &status, 0);
    return 0;
}