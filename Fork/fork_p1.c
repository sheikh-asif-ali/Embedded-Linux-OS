#include<stdio.h>
#include<unistd.h>
int main()
{
	int n=fork();
	if(n!=0)
	printf("\n1st fork\n");
	else if(n==1)
	printf("\n2nd fork\n");
	else
        printf("\nLast fork\n");
return 0;
}
