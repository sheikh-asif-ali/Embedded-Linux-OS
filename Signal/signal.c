#include<stdio.h>
#include<signal.h> //to use signal keyword
#include<unistd.h> //to use sleep
void sig_handler(int signo)
{
	//if(signo==SIGINT)
		printf("Received SIGINT\n");
}
int main(void)
{
	int i=1;
	if(SIG_ERR == signal(SIGINT,sig_handler) )
		printf("\nCant't Catch SIGINT\n");
	while(i)
	{
		//printf(":) I'm Working \n");		
		sleep(1);
		//i++;
	}
	return 0;
}
