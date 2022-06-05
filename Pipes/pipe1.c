#include<stdio.h>
#include<unistd.h>
int main()
{
	int pipe_fd[2]; //pipe_fd[0]-->read, pipe_fd[1]-->write
	int rtn_status;
	char writemessage[2][20]={"Pehla Akshar","Dusra Vakhya"}; //[0][20]="Pehla Akshar", [1][20]="Dusra Vakhya"
	char readmessage[20];
	
	rtn_status = pipe(pipe_fd); //calling pipe function to create pipe & passing variable to it
	if (rtn_status == -1)	//return type of pipe(); is 0 for true & -1 for error
	{
		printf("Unable to create pipe\n");
		return 1;
	}

	printf("Writing to pipe ->=== Message 1 is: %s\n", writemessage[0]);
		write(pipe_fd[1], writemessage[0], sizeof(writemessage[0]));	//write(descreptor[1]i.e.permission,data,size);
	
	read(pipe_fd[0], readmessage, sizeof(readmessage)); 			//read(descreptor[0]i.e.permission,data,size);
		printf("Reading from pipe ===–> Message 1 is: %s\n", readmessage);
	
	printf("Writing to pipe ->=== Message 2 is: %s\n", writemessage[1]);
		write(pipe_fd[1], writemessage[1], sizeof(writemessage[1]));

	read(pipe_fd[0], readmessage, sizeof(readmessage));
		printf("Reading from pipe ===–> Message 2 is: %s\n", readmessage); 
	return 0;
}
