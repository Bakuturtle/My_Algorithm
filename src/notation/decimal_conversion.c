#include <stdio.h>
int Ipow(int a, int b){

    int i;
    int p = a;
    for(i=1; i < b; i++){
        p = p*a;
    }
    return p;
}

int main(void){
    int number, notion,temp;
    int Value,i;
    printf("1~10 decimal convert\n");
    printf("number: ");
    scanf("%d", &number);
    printf("notion:");
    scanf("%d", &notion);
    if(notion >=10){
        printf("\n Please enter a number under 10");
        return EOF;
    }

    for (i = 0; number >= 1; i++) {
        temp = number % notion;
        number = number / notion;
        Value += temp * Ipow(10, i);
    }
    Value += number* Ipow(10, i);
    printf("%d",Value);

    return 0;
}