#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int nCount = atoi(argv[1]);
    char *p = 0;

    printf("allocation memories\n");
    for(int i= 0; i<nCount; i++)
        p = (char*)malloc(4096);

    printf("Done...\n");
    getchar();

    return 0;
}