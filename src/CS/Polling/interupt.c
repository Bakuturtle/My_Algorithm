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

//이 소스코드는 실행파일을 실행시 PS를 GETPID로 확인하고
// 사용자 정의 1,2 시그널을 보낼시에 특정 메서드의 기능을 수행하는것이다.
// 시그널과 특정 메서드 수행은 signal 메서드에서 정해진다.
