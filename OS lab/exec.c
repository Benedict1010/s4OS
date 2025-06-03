#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
    int pid;
    char*args[] = {"/bin/ls","-1",0};
        pid=fork();
        if(pid==-0)
        {
            execv("/bin/lh",args);
            printf("child process");

        }
        else
        {
            //wait();
            printf("parent process");
            exit(0);
        }
}