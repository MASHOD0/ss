#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

static void charatatime (char *); 

int main (void) {

    pid_t pid;
    if ((pid=fork( ))< 0) { 
        /*if fork() returns 0 -> child process, 
         if > 0 its parent process, 
         if < 0 its an error*/ 
        printf("fork error\n");
    }
    else if(pid==0) {  
        charatatime("Output from child\n");
    }
    else {
        charatatime("Output from parent\n");
    }

    exit(0);
}
static void charatatime(char *str) {
    char *ptr;
    int c;
    setbuf(stdout,NULL); 
    /* disables buffering on the standard output stream. 
    the standard output stream is line-buffered, 
    which means that the output is buffered until a newline character is encountered. 
    When you call setbuf(stdout, NULL), 
    it disables this buffering and makes the output unbuffered */
    for(ptr=str;(c=*ptr++)!=0;)
        putc(c,stdout);
}
