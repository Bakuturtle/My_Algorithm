#include <stdio.h>
#include <stdbool.h>

int main(void){
    int complement = 10;
    complement = ~complement;

    printf("%d", complement);

    return 0;
}