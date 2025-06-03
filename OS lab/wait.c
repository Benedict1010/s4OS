#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void) {
    int pid, status,exitch;
    if((pid=fork())==-1)
    {
        perror("error");
        exit(1);
    }
    if(pid==0){
        sleep(1);
        printf("child process");
        exit(0);
    }
    else{
        printf("parent process");
        if((exitch=wait(&status))==-1)
        {
            perror("during wait");
            exit(1);
        }
        printf("parent existing");
        exit(0);
    }
}