#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <semaphore.h> // 세마포어 관련 기능들이 담긴 헤더파일이다.

void* mythread_r(void* ptr);
void* mythread_w(void* ptr);

sem_t g_mutex; //semaphore의 데이터를 담는 자료형이다. 

int main(int argc, char* argv[]){
    pthread_t thread1, thread2;
    int nValue = 0;

    //
    sem_init(&g_mutex, 0, 1); 

    pthread_create(&thread1, NULL, *mythread_r,(void*)&nValue);
    pthread_create(&thread2, NULL, *mythread_w,(void*)&nValue);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    //
    sem_destroy(&g_mutex);

    return 0;
}

void* mythread_r(void* p_Value){
    int* p_nValue = (int*)p_Value;

    do{
        sem_wait(&g_mutex);
        if(*p_nValue % 2 == 0){
            usleep(500000);
            printf("%d is even number!\n", *p_nValue);
        }
        else{
            usleep(500000);
            printf("%d is odd number!\n", *p_nValue);
        }
        sem_post(&g_mutex);
        usleep(500000);
    }while(1);
    return p_nValue;
}
void* mythread_w(void* p_Value){
    int* p_nVaule = (int*)p_Value;

    do{
        sem_wait(&g_mutex);
        (*p_nVaule)++;
        sem_post(&g_mutex);
        usleep(500000);
    }while(1);

    return p_nVaule;
}
//스레드가 공유자원을 베타적 사용을 보장받기위해 임계구역을 드나들때 사용하는 동기화 매커니즘중 하나이다. 
// 세마포어(semaphore): 여러 Process혹은 Thread 접근을 막아주는 역할을 한다. (동기화 대상은 하나이상)
// 뮤텍스(Mutex): 하나의 Process 혹은 Thread가 접근하는걸 막아줌 (동기화 대상은 하나이다.)