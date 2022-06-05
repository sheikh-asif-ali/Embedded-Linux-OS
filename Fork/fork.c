#include<stdio.h> 
//#include<sys/types.h>
#include<unistd.h> //to use keyword pid,getpid & fork
int main()
{
	pid_t child_pid; // pid_t is keyword,child_pid is variable

	printf("The main program process ID is--getpid-- %d\n",(int)getpid()); 
	child_pid=fork();

	if(child_pid!=0) //parent process i.e child_pid==1
	{
		printf("Inside if condi.... Parent's Process ID is: %d\n",(int)getpid());
		printf("Inside if condi.... Child's Process ID is: %d\n",(int)child_pid);
	}
	else	//child process i.e child_pid==0
	{
		printf("\nInside else part... This is the child process,with ID: %d\n\r",(int)getpid());

	}
	return 0;
}
