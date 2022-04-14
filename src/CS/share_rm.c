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

	// int shmctl(int shmid, int cmd, struct shmid_ds *buf)
	// System v에서(유닉스 시스템V라고 나온다) 메모리 컨트롤을 해주는 함수이다.
	// IPC_STAT, IPC_SET, IPC_RMID, IPC_INFO, SHM_INFO 등 있다. 리눅스 한정 플래그도 끼어있는거같다.


	//shmid_ds 구조체의 구조 

	//struct shmid_ds {
	//               struct ipc_perm shm_perm;    /* Ownership and permissions */
	//               size_t          shm_segsz;   /* Size of segment (bytes) */
	//               time_t          shm_atime;   /* Last attach time */
	//               time_t          shm_dtime;   /* Last detach time */
	//               time_t          shm_ctime;   /* Creation time/time of last
	//                                               modification via shmctl() */
	//               pid_t           shm_cpid;    /* PID of creator */
	//               pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
	//               shmatt_t        shm_nattch;  /* No. of current attaches */
	//               ...
	//           };
	//


    if(shmctl(nShmId, IPC_RMID, NULL)){
        printf("%Deleting Shared Memory has been faild.\n");
        return 0;
    }
    printf("Shared Memory is deleted succesfully\n");


    return 0;
}

//argv의 값을 int형으로 변환시키는 atoi를 사용하여 nShmld에 값을 바꾼다.
//그리고 만약 nShmld의 값의 삭제가 실패된다면 if문 true값으로  delete ..이 실행되고 return 0으로 종료됨
// 성공한다면 아래의 shared ... 이 실행하고 종료된다.
