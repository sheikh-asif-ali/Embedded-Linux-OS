#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int pid;
	pid = fork();
	
	if (pid == 0)
	{
		system("ls -l");
		sleep(10);
		system("date");
	}
	else
	{
		sleep(20); //change with 3
	}
	return 0;
}
