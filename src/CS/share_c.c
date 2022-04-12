#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int nShmId=0;
    char *pShared=0;
    nShmId = shmget(0x1234, 4096, IPC_CREAT|IPC_EXCL|0666);
    printf("Shared Memory ID is %d\n", nShmId);
    pShared = (char*)shmat(nShmId,NULL,0);
    memset(pShared,0,4096);

    for(int i =0; i<20; i++){
        printf("Data: %s\n",pShared);
        sleep(1);
    }
    shmdt(pShared);
    return 0;
}