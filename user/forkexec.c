#include "user/user.h"

int main(){
    int pid, status;

    pid = fork();

    //child
    if(pid == 0){
        char* argv[] = {"echo", "THIS", "IS", "ECHO", 0};
        exec("echo", argv);

        //if it cannot call system call -- echo
        printf("Failed to call echo\n");
        exit(0);
    }else{
        //parent

        printf("Parent waiting\n");
        wait(&status);
        printf("The child exited with status %d\n", status);
    }

    exit(0);
}