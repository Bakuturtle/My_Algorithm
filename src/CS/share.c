#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(void){
    int nShmId=0;

    //int shmget(key_t key, int size, int shmflg)
    //IPC_CREATE 해당 공유메모리가 없으면 새로 생성
    //IPC_EXCL 공유 메모리가 이미 있다면 실패로 반환
    // 마즈막은 flag 변수를 사용하는데 특정조건의 충족되었음을 알려주는 역할을 한다.
    // shmget에선 IPC_CREATE, EXCL ,HUGETLB, HUGETLB_2MB,SHM_NORSERVE, 등 있다.
    // 최하위 비트는 쉽게말해서 권한설정을 정하는 플래그이다. 777 권한이랑 같다.
    nShmId = shmget(0x1234, 4096, IPC_CREAT|IPC_EXCL|0666);
    printf("Shared Memory ID is %d\n", nShmId);

    return 0;
}
// 이 소스코드는 16진수기준 1234라는 공유메모리에 4096사이즈만큼 위 플레그와 
// rw-rw-rw 권한을 지정함
