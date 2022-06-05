#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2], status, pid, i;
	char w_msg[5][20]={"Pehla", "Dusra", "Tisra", "Choutha", "Panchwa"};
	char r_msg[20];
	status = pipe(fd);
	if (status == -1)
	{
		printf("Unable to create pipe\n");
		return 1;
	}
	pid = fork();
	if (pid == 0)	// Child Process
	{
		printf("\n");
		for(i=0;i<5;i++)
		{
		read(fd[0], r_msg, sizeof(r_msg));
			printf("In Child Process: Message %d is-: %s\n",i+1, r_msg);
		}	
	} 
	else	// Parent Process 
	{ 
		for(i=0;i<5;i++)
		{
		printf("In Parent Process - Writing to pipe - Message %d is-: %s\n",i+1, w_msg[i]);
			write(fd[1], w_msg[i], sizeof(w_msg[i]));
		}	
	
	}
	return 0;
}
