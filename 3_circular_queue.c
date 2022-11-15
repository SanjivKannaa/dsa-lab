#include<stdio.h>

int queue[10];
int f=-1, r=-1, count=0;

int enqueue(int element){
    if (count==9){
        printf("Queue full");
        return 0;
    }
    if (f==-1){
        f++;
        queue[++r] = element;
        count++;
        return 0;
    }
    count++;
    queue[++r] = element;
}

int dequeue(){
    if (count==0){
        printf("Queue empty");
    }
    f++;
    count--;
}

int main(){
    int option, element;
    while(1){
        printf("\n\nEnter the operation number \n1. enqueue\n2. dequeue\n3. view top\n4. exit\n>>");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the new element : ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (f>r || f==-1){
                    printf("queue is empty");
                }else{
                    printf("top element => %d", queue[r]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("invalid option...try again");
        }
    }
}