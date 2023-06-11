#include<stdio.h>
int main() {
    
    int ch,rv; 
    char cmd[10]; //string to store command
    rv=fork(); // create child process

    if(rv==0) { // if its child process
        do {
            // runs commands
            printf("\nEnter a command\n");
            scanf("%s",cmd);
            system(cmd);
            printf("\n1 : continue\n0 : exit\n");
            scanf("%d",&ch);
        }
        while(ch!=0);
    }
    else { 
        wait(0);
        printf("\nChild terminated\n");
    }
    return 0;
}