#include<stdio.h>
#include<string.h>
#include<unistd.h>
int i,count;
int str[50];
int main()
{
	printf("Enter an Integer string: \n");
	scanf("%d",str);
	count=strlen(str);

	pid_t f;
	f=fork();
	if(f!=0)
	{
		printf("INSIDE PARENT AREA\n");
		for(i = count ; i >= 0; i--)
                {
                        printf("%c", str[i]);    
                }
	}
	else
	{
		printf("\nINSIDE CHILD AREA\n");
		count=strlen(str);
                printf("No of character is:%d\n",count);
	}
return 0;
}
