#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(){
    int pid;
    pid = fork();

    //child
    if(pid == 0){

        //closes the standard outfile descriptor
        close(1);

        open("output.txt", O_WRONLY | O_CREATE);

        char* argv[] = {"echo", "THIS", "IS", "ECHO", 0};
        exec("echo", argv);

        printf("exec failed");
        exit(1);

    }else{
        //parent
        //wait((int*) 0) == wait(null)
        wait((int*) 0);
    }

    exit(0);
}