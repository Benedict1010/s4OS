#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
    struct stat*nfile ;
    char *path,path1[10];
    nfile=(struct stat*) malloc (sizeof(struct stat));
    printf("enter the name of file to access statistics \n");
    scanf("%s",path);
    stat(path1,nfile);
    printf("user id %d\n",nfile->st_uid);
    printf("block size %d\n",nfile->st_atime);
}