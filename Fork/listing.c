#include<stdio.h>
#include<stdlib.h> //To use abort
//#include<sys/types.h>
#include<unistd.h> //To use fork,spawn

int spawn(char* program, char** arg_list)
{
	pid_t child_pid;
	child_pid= fork();
	if(child_pid!= 0)
		return child_pid;
	else
	{
		execvp(program,arg_list);
		fprintf(stderr,"an error occured in execvp\n");
		abort();
	}
}
int main()
{
	char* arg_list[]={"ls","-l","/",NULL};
	spawn("ls",arg_list);
	printf("Done with main program \n");
	return 0;
}
