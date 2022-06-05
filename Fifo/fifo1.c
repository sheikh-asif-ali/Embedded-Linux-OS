// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int fd;
	char *myfifo = "/home/ali/EOS_ASIF/myfifo"; // FIFO file path
	
	// Creating the named file(FIFO)
	mkfifo(myfifo, 0666); // mkfifo(<pathname>, <permission>)
	char arr1[80], arr2[80];
	while (1)
	{
		// Open FIFO for write only
		fd = open(myfifo, O_WRONLY);
		// Take an input arr2ing from user.
		fgets(arr2, 80, stdin); // 80 is maximum length
		// Write the input arr2ing on FIFO
		// and close it
		write(fd, arr2, strlen(arr2)+1);
		close(fd);
		
		// Open FIFO for Read only
	fd = open(myfifo, O_RDONLY);
		// Read from FIFO
	read(fd, arr1, sizeof(arr1));
		// Print the read message
	printf("User2: %s\n", arr1);
	//printf("%s\n", arr1);
	close(fd);
	}
	return 0;
}
