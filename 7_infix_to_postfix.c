#include<stdio.h>

char stack[20];
int top=-1;



int push(char element){
    if (top==9){
        printf("Stack overflow");
        return 0;
    }
    stack[++top]=element;
}

int pop(){
    if (top==-1){
        printf("Stack underflow");
        return 0;
    }
    --top;
}

