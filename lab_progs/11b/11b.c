/*
Write a C/C++ program which demonstrates inter-process communication between a reader process and a writer
process. Use mkfifo, open, read, write and close APIs in your program.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(int argc,char *argv[]) {
    int fd,num1,num2;
    char buf[100];
    /* write case */ 
    if(argc==3) { // 3 cli args required in write case: 2.fifo name, 3. charecters to write into fifo
        mkfifo(argv[1],0666); /*mkfifo -> creates a fifo (named pipe) argv[1] -> name of the fifo, 
                                0666 -> specifies permissions for the fifo-- can read from and written by any user */
        fd=open(argv[1],O_WRONLY); /*opens named pipe for write only(O_WRONLY), argv[1]-> fifo name*/
        num1=write(fd,argv[2],strlen(argv[2])); /*write() writes argv[2] to `fd` in size of `strlen(argv[2])` and returns no. of bytes written*/
        printf("no of bytes written%d\n",num1);
    }
    /* read case */
    if(argc==2) {
        fd=open(argv[1],O_RDONLY); /*opens fifo(argv[1]) in read only mode(O_RDONLY)*/
        num2=read(fd,buf,sizeof(buf));/*reads `fd`, to buf*/
        buf[num2]='\0';/*append null charecter to buf a string to print*/
        printf("the message size %d read is %s",num2,buf);
    }
    close(fd);
    unlink(argv[1]); // unlinks the fifo
    return 0;
}