#include<stdio.h>
#include<unistd.h>
int main()
{
	int pipefd[2], rtnstatus, pid;
	char writemessages[2][20]={"Pehla Message", "Dusra Message"};
	char readmessage[20];
	
	rtnstatus = pipe(pipefd);
	if (rtnstatus == -1)
	{
		printf("Unable to create pipe\n");
		return 1;
	}
	pid = fork();
	// Child Process
	if (pid == 0)
	{
		printf("\n");
		read(pipefd[0], readmessage, sizeof(readmessage));
			printf("In Child Process: Message 1 is-: %s\n", readmessage);
		read(pipefd[0], readmessage, sizeof(readmessage));
			printf("In Child Process: Message 2 is-: %s\n", readmessage);
	}
	// Parent Process 
	else 
	{ 
		printf("In Parent Process - Writing to pipe - Message 1 is-: %s\n", writemessages[0]);
			write(pipefd[1], writemessages[0], sizeof(writemessages[0]));
		printf("In Parent Process - Writing to pipe - Message 2 is-: %s\n", writemessages[1]);
			write(pipefd[1], writemessages[1], sizeof(writemessages[1]));
	}
	return 0;
}
