#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void callback_sig_handler(int nSigNumber);

int main(void){
    printf("PID: %d\n", getpid());

    //void (*signal(int sig, void(*func)(int)))(int)
    signal(SIGUSR1, callback_sig_handler);
    signal(SIGUSR2, callback_sig_handler);

    for(int i=0; ; i++){
        if(i%4==0){
            printf("\r-");
        }
        else if(i%4==1){
            printf("\r\\");
        }
        else if(i %4 ==2){
            printf("\r|");
        }
        else{
            printf("\r/");
        }
        // int fflush(FILE * stream)
        //화면 출력을 도와주는 메서드
        fflush(stdout);
        usleep(50000);
    }
    return 0;

}

void callback_sig_handler(int nSigNumber){
    printf("We just got a signal(%d).\n", nSigNumber);
}

// 프로세스에 signal을 보내면 출력해주는 기능인데
// 10하고 12의 시그널을 kill으로 보내면 callback_sig_handler 메서드가
// sgnial 함수에서 설정했기에 작동한다.
