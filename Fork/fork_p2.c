#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t n;
     	n=fork();
	 
    	if(n!=0)
    
    printf("parent ID %d& ID: %d, PPID:%d\n",n,(int)getpid(),getppid());
    else
	    printf("child value %d& ID:%d,PPID: %d",n,(int)getpid(),getppid());
    return 0;
}
