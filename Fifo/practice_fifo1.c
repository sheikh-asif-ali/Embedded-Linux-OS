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
		file=open(path,O_RDONLY);
		read(file,String1,sizeof(String1));
		printf("2nd User: %s\n",String1);
		close(file);

		file=open(path, O_WRONLY);
		printf("2nd User: ");
		fgets(String2,50,stdin);
		write(file, String2, strlen(String2)+1);
		close(file);
	}
	return 0;
}
