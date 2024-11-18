#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(){

    //fd == 0 -> 
    int fd = open("output.txt", O_WRONLY | O_CREATE);
    if(fd == -1){
        printf("Error: failed to open file");
        exit(1);
    }

    write(fd, "ooo\n", strlen("ooo")+1);
    close(fd);
    exit(0);

}