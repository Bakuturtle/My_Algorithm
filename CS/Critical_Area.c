#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void* mythread_r(void* ptr); //void 포인터는 주소값을 담는 역할을 한다. 형변환이 자유롭다.
void* mythread_w(void* ptr);

int main(int argc, char* argv[]){
    pthread_t thread1, thread2; // pthread_t란 쓰레드의 관한 정보를 담고있는 자료형이다.
    int nValue = 0;

    //pthread_creat 란 호출될때마다 새로운 쓰레드를 만드는 함수로 새로운 쓰레드는 start_rountine 함수로 실행됨
    //위 함수의 구조는 int pthread(pthread_t *thread, const pthread_attr_t * attr, void *(*start_routine) (void *), voud *arg);
    //NULL은 default attr 를 지닌다.
    // 성공시 return 0, 실패시 return error number
    //errors: [EAGAIN], [EINVAL], [EPERM]
    pthread_create(&thread1, NULL, *mythread_r,(void*)&nValue);
    pthread_create(&thread2, NULL, *mythread_w,(void*)&nValue);

    // 대상 쓰레드가 종료되지않으면 종료될떄 까지 중단하는 함수이다.
    // pthread_join의 구조는 int ptread_join(pthread_t, void **value_ptr);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}

void* mythread_r(void* p_Value){
    int* p_nValue = (int*)p_Value;

    do{ //do while은 while이랑 다르게 처음은 반드시 실행됨
       if(*p_nValue % 2 == 0){  // p_nVaule가 짝수면 참.
            usleep(500000); //0.5초 기다림
            printf("%d is even number!\n", *p_nValue);
        }
        else{
            usleep(500000);
            printf("%d is odd number!\n", *p_nValue);
        }
        usleep(500000);// 
    }while(1); // 조건이 참이면 반복 , 1이니 무한반복
    return p_nValue; // 리턴할때 void 포인터 이므로 int형일떈 int로 반환하게 가능하고 배열도 리턴이 가능하다.
}
void* mythread_w(void* p_Value){
    int* p_nVaule = (int*)p_Value;

    do{ 
        (*p_nVaule)++; //p_nVaule가 후치증감연산 적용;
        usleep(500000);
        
    }while(1);

    return p_nVaule;
}

//Critical_Aread는 임계구역으로 둘 이상이 쓰레드가 접근하면 안되는 공유자원에 접근하는것을 말한다.
//홀짝 출력이 이상하게 나오는 이유는 두 쓰레드가 출력해야될때 증감연산이 되어버리기 떄문이다.