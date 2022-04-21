#include <stdio.h>
#include <unistd.h>

int main(void){
    for(int i=0;;i++){
        // int access(const char *path, int __type);
        // amode 종류는 R_OK, W_OK, X_OK, F_OK로 DEFINE으로 전처리됨
        //F_OK는 파일이 존재하는지 여부를 묻는 여부이다.
        // access는 특정 모드가 true면 0 false 면 -1를 반환한다.
        if( access("./test.txt",F_OK) == 0){
            printf("There is a file(%05d).\n",i);
        }
        usleep(100000);
    }
    return 0;
}
//이 프로그램은 ./test.txt의 파일이 F_OK (존재한다면) PRINTF메서드가 실행되는 것 이다.
//이 프로그램이 동작중에 만약 test.txt 파일이 삭제된다면 printf 메서드는 실행되지 않는다.