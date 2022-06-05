#include<stdio.h>
#include<string.h>
#include<unistd.h>
int i,count;
char str[50];
int main()
{

	printf("Enter a string: \n");
	scanf("%s",str);
	count=strlen(str);
	pid_t f;
	f=fork();

	if(f!=0)
	{
		printf("INSIDE PARENT AREA\n");
		count=strlen(str);
		printf("No of character is:%d\n",count);
	}
	else
	{
		printf("\nINSIDE CHILD AREA\n");
		for(i = count ; i >= 0; i--)
		{
        		printf("%c", str[i]);        
	       	}
	}
return 0;
}
