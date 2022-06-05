#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>
#include <sys/stat.h>
int main()
{		
	int file;
	char String1[50],String2[50];
	char *path = "/home/ali/EOS_ASIF/prac_fifo";
	mkfifo(path,0666);
	while(1)
	{
		file=open(path, O_WRONLY);
		printf("1st User: ");
		fgets(String1,50,stdin);
		write(file, String1, strlen(String1)+1);
		close(file);
		
		file=open(path,O_RDONLY);
		read(file,String2,sizeof(String2));
		printf("1st User: %s\n",String2);
		close(file);
	}
	return 0;
}
