#include<stdio.h>
#include<stdbool.h>
#define MAX_STACK_SIZE 5
 
int stack[MAX_STACK_SIZE];
int top=-1;
 
int IsEmpty(){
    if(top<0)
        return true;
    else
        return false;
    }

int IsFull(){
    if(top>=MAX_STACK_SIZE-1)
        return true;
    else
        return false;
}
 
void push(int value){
    if(IsFull()==true)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top]=value; 
}
 
int pop(){
    if(IsEmpty()==true)
        printf("스택이 비었습니다.");
    else 
        return stack[top--];
}
 
int main(){
    int i = 0;
    push(++i);
    push(++i);
    push(++i);
    push(++i);
    push(++i);
    push(30);
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());

    printf("%d ",pop());
 
    return 0;
}
 