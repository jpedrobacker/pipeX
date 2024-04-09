#include "inc/pipex.h"

/*int main()
{
	int fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	if (access("example.txt", R_OK) != -1)
	{
		ft_printf("I have permission\n");
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_printf("muda isso!\n");
	}
	else
		ft_printf("I don't have permission!\n");

	return (0);
}*/

/*int main()
{
	char *args[3] = {"ls", "-l", NULL};

	ft_printf("This will be executed.\n");
	execve("/bin/ls", args, NULL);
	ft_printf("This will not be executed.\n");

	return (0);
}
*/

/*int main()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
		ft_printf("This is the child process. (pid: %d)\n", getpid());
	//else
	//	ft_printf("This is the parent process. (pid: %d)\n", getpid());
	return (0);
}
*/
int main()
{
	int fd[2];
	pid_t pid;
	char bf[13];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "Hello parent!", 13);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		read(fd[0], bf, 13);
		close(fd[0]);
		ft_printf("Message from child: '%s'\n", bf);
		exit(EXIT_SUCCESS);
	}
}
