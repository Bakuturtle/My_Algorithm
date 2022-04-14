#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>


int main(void){

    int nShmId=0;
    char *pShared=0;

    nShmId = shmget(0x1234, 4096,IPC_CREAT|0666);
    printf("Shared Memory ID is %d\n", nShmId);

    pShared = (char*)shmat(nShmId, NULL, 0);

    memset(pShared, 0, 4096);
    
    for(int i=0; i<20; i++) {
        printf("Data: %s\n", pShared);
        sleep(1);
    }
    shmdt(pShared);
    return 0;
}

//이 소스코드는 사실 뭔지 모르겠다 SHM_r이니 뭘 읽는거같은데
//RD관련 플래그를 사용하지도않아서 pShared를 딱히 뭘 지정하지않아서 동적으로 할당된 4096사이즈의 첫번쨰 인덱스가 '\0' 일테니 이거  읽고 다음루프로 건너뛰고 하는거같다.
//그리고 마즈막엔  pSAhared attach를 해제한다.
