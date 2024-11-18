//System call -- copy input to output

#include "kernel/types.h"
#include "user/user.h"

int main(){

    char buf[64];
    int n;
    while(1){

        //get the status of read()
        //Varible n holds the number of bytes that were actually read by the read function
        //e.g., “hello world” (11 bytes), n will be 12
        n = read(0, buf, sizeof(buf));

        //When pressing Ctrl+D, read() will return 0
        //Exit copy()
        if(n == 0){
            break;
        }

        if(n == -1){
            printf("Error: Read failed\n");
            exit(-1);
        }

        //Checking while calling write()
        if(write(1, buf, n) == -1){
            printf("Error: write failed\n");
            exit(-1);
        }

    }
    exit(0);
}