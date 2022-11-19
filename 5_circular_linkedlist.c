#include<stdio.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert_begin(int element){
    // printf("bruh1");
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    // printf("%f", newnode);
    newnode->data = element;
    newnode->next = head;
    head=newnode;
}

void insert_last(int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    struct node *current = head;
    while (current->next!=head){
        current = current->next;
    }
    current->next = newnode;
}

void insert_position(int element, int position){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    
}




void delete_first(){
    struct node *current = head;
    if (current!=NULL){
        struct node *temp = current->next;
        head = temp;
        free(current);
    }
}

void delete_last(){
    struct node *current = head;
    struct node *temp;
    if (current!=NULL){
        while(current->next!=NULL){
            temp = current;
            current = current->next;
        }
        temp->next = head;
        free(current);
    }
}

void delete_position(int position){
    return 0;
}



void show(){
    struct node *current = head;
    printf(" -> %d", current->data);
    current = current->next;
    while (current != head){
        printf(" -> %d", current->data);
        current = current->next;
    }
}

int main(){
    int option, element, position;
    while(1){
        printf("\n\nEnter the operation number \n1. insert at first\n2. insert at last\n3. insert at position\n4. delete at first\n5. delete at last\n6. delete at position\n7. show LL\n8. exit\n>>");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the new element : ");
                scanf("%d", &element);
                insert_begin(element);
                break;
            case 2:
                printf("Enter the new element : ");
                scanf("%d", &element);
                insert_last(element);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d", &position);
                printf("\nEnter the new element : ");
                scanf("%d", &element);
                insert_position(element, position);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d", &position);
                delete_position(position);
                break;
            case 7:
                show();
                break;
            case 8:
                return 0;
            default:
                printf("invalid option...try again");
        }
    }
}