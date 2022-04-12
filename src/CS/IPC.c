#include <stdio.h> // standard input/output HEADER
#include <unistd.h> // Header file providing api of posix(Unix based) OS
#include <string.h> // Header dealing with mem and string
#include <stdbool.h> // Header with bool, true, false

int main(void){
    //BUFSIZ는 stdio에 정의되어있는 매크로 상수 인데 나는 기본이 8192로 정의되어있다 
    //setbuf 함수를 사용하기위해 사용한다.
    char pBuffer[BUFSIZ];  
    int nLen = 0;

    do{
        //memset은 함수의 메모리를 할당하는 함수이다.
        //memset의 구조는 void *memset(void *ptr, int c, size_t n);
        //첫번쨰는 변경하고자 하는 인자의 포인터, 두번쨰는 변경하고자 하는 값, 세번째는 변경하고자 하는 길이
        //malloc와 다르게 초기화를 한 다음 할당한다. 
        memset(pBuffer,0,BUFSIZ);
        // 파일을 읽기위한 함수로 stdio에 정의된 함수이다.
        // ssize_t read (int fd, void *buf, size_t nbytes)
        nLen = read(0, pBuffer, BUFSIZ);
        //파일을 다 읽으면 종료하도록 함
        if(nLen>0){
            printf("%s", pBuffer);
        }
        else
            break;
    }while(true);
    return 0;
}
//IPC란 프로새스간 데이터를 공유하기 위한 기법
//위 프로그램은 A프로세스의 출력을 B프로세스(gcc로 컴파일한 이 소스 코드)로 처리하는 프로그램이다.
//
