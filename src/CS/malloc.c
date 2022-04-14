#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int nCount = atoi(argv[1]); //문자열 형태의 숫자를 숫자로 바꿔주는 함수이고 그것을  nCOunt에 저장하는것이다.
    char *p = 0; 

    printf("allocation memories\n");
    for(int i= 0; i<nCount; i++) //argv에 입력한 숫자만큼 반복해서 malloc로 할당
        p = (char*)malloc(4096); //512바이트 할당

    printf("Done...\n");
    getchar();// 버퍼 비움

    return 0;
}
// c에서는 가비지컬렉션같은 메모리 관리 기능이 없기에 할당하면 무조건적으로 해제해야되는데
// free를  하지않기에 메모리 누수를 발생시키는 코드이다. 
