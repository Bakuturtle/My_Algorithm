#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char* argv[]){

    int nShmId=0;

    if(argc !=2){
        printf("We need one argument!!\n");
        return 0;
    }
    nShmId = atoi(argv[1]);
    printf("Shared Memory ID is %d\n", nShmId);

    if( shmctl(nShmId, IPC_RMID, NULL)){
        printf("%Deleting Shared Memory has been faild.\n");
        return 0;
    }
    printf("Shared Memory is deleted succesfully\n");


    return 0;
}
