#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{       
        int a[10]={10,1,2,3,4,5,6,7,8,9};
        int sumOdd=0,sumEven=0,n,i;
        n = fork();

        if(n!=0) //Parent process 
        {
                for(i=0;i<10;i++)
                {
                        if(a[i]%2==0)
                        sumEven=sumEven+a[i];
                }
                printf("In Parent Process \n");
                printf("Sum of Even no is %d\n",sumEven);
        }
        else //child process i.e n==0
        {
                for(i=0;i<10;i++)
                {
                        if(a[i]%2!=0)
                        sumOdd=sumOdd+a[i];
                }
                printf("\nIn Child Process \n");
                printf("Sum of Odd no is %d\n",sumOdd);
        }
        
        return 0;
}

