#include <stdio.h> // standard input/output HEADER
#include <unistd.h> //Header file providing api of posix(Unix based) OS
#include <string.h> //Header dealing with mem and string
#include <stdbool.h> //Header with bool, true, false

int main(void){
    char pBuffer[BUFSIZ];
    int nLen = 0;

    do{
        memset(pBuffer,0,BUFSIZ);
        nLen = read(0, pBuffer, BUFSIZ);
        if(nLen>0){
            printf("%s", pBuffer);
        }
        else
            break;
    }while(true);
    return 0;

}
