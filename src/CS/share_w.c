#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int nShmId=0;
    char *pShared=0;
    nShmId = shmget(0x1234, 4096, IPC_CREAT|0666);
    printf("Shared Memory ID is %d\n", nShmId);
    //shmat은 공유메모리에 접근하기위해 연결해주는 함수다.
    // void *shmat(int shmid,const void* shmaddr, int shmflg);
    
    // void* shmaddr 이 null이면 커널에서 알아서 주소를 반환해줌
    // NULL이 아니고 shmflg의 플레그의 역할에 따라 shmat의 작동이 달라짐
    // SHM_RDONLY, SHM_RND 등 있음
    pShared = (char*)shmat(nShmId,NULL,0); 
    memset(pShared,0,4096);//pShare에 0 값을 4096 바이트만큼 채움

    for(int i =0; i<20; i++){
        sprintf(pShared, "Shared :%d",i); //출력 + 변수저장을 하게 해주는 메서드
    }
    shmdt(pShared); //공유메모리를 분리하는 메서드
    return 0;
}

// 이 소스코드의 동작 과정은 nShmId 라는 변수에 shmget이라는 공유메모리
// 지정 메소드를 사용한 후에
// pShared라는 포인터형 변수에 shmat을 이용하여 공유메모리를 연결했다.
// 그런다음에 sprintf라는 출력과 저장을 해주는 함수를 이용하여 20번정도 특정 조건을 루프
// 근데 까보니 pShared에 sprintf로 할당한 값이  shmdt으로 분리되면서 초기화되던데
// sprintf가 의미있는지는 모르겠다. + 어차피 배열형태로 할당을 하는것도 아니라서...
