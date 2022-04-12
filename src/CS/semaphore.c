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

//main의 매개변수
//int argc <- 함수의 전달되는 인수의 갯수
//char* argv[] <- 함수에 전달된 실질 인수의 값의 포인터배열, (MAX는 argc의 갯수만큼)
//여긴 없지만 cahr *envp[]도 있다. 운영체제의 환경변수를 넘겨받는다.
int main(int argc, char* argv[]){
    pthread_t thread1, thread2;
    int nValue = 0;

    //unnamed의 세마포어를 만드는 함수이다.
    //int sem_init(sem_t *sem, int pshared, unsigned int value);
    // pshared는 0이면 프로세스 내부에서만 0이 아니면 프로세스간 세마포어를 공유함
    sem_init(&g_mutex, 0, 1); 

    pthread_create(&thread1, NULL, *mythread_r,(void*)&nValue);
    pthread_create(&thread2, NULL, *mythread_w,(void*)&nValue);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    //unnnamed 세마포어 객체를 삭제 및 할당해제
    //int sem_destroy(sem_t *sem);

    sem_destroy(&g_mutex);

    return 0;
}
// 위 프로그램은 쓰레드가 임계지역충돌(Critical Area Collision) 을 막기위해 
// mythread_r의 함수와 mythread_w의 함수에 sem_wait과 sem_post를 걸어서 막은것이다.
//다만 첫번째에선 따로 뭘 설정한게 아니라 sem_wait이 뭐가 먼저 걸릴지는 컴퓨터 상황에따라 다른거같다
//첫 시작이 0이 될 수도 있고 1이 될 수도 있다.

void* mythread_r(void* p_Value){
    int* p_nValue = (int*)p_Value;

    do{
        //sem_wait이란 세마포어(semaphore)를 얻을떄 까지 기다리는 함수
        //int sem_wait(sem_t *sem);
        //비슷한 wait 관련 함수중에 sem_trywait, sem_timedwait 이란 함수도 있다.
        sem_wait(&g_mutex);
        if(*p_nValue % 2 == 0){
            usleep(500000);
            printf("%d is even number!\n", *p_nValue);
        }
        else{
            usleep(500000);
            printf("%d is odd number!\n", *p_nValue);
        }
        //sem_post란 세마포어를 되돌려주는 함수이다. 세마포어의 값이 증가한다.
        //int sem_post(sem_t *sem);
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
// 세마포어(Semaphore): 여러 Process혹은 Thread 접근을 막아주는 역할을 한다. (동기화 대상은 하나이상)
// 세마포어는 상호 배제(Mutual Exclusion) 알고리즘으로 임계 구역을 만들어서 자원을 보호한다.
// 뮤텍스(Mutex): 하나의 Process 혹은 Thread가 접근하는걸 막아줌 (동기화 대상은 하나이다.)