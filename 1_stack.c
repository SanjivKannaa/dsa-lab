#include<stdio.h>

int stack[10];
int top=-1;

int push(int element){
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

int main(){
    int option, element;
    while(1){
        printf("\n\nEnter the operation number \n1. push\n2. pop\n3. view top\n4. exit\n>>");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the new element : ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (top==-1){
                    printf("stack is empty");
                }else{
                    printf("top element => %d", stack[top]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("invalid option...try again");
        }
    }
}