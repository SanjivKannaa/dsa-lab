#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *root = NULL;


/*
// operations to be done
    1. insert element
    2. delete element
    3. inorder transversal
    4. preorder traversal
    5. postorder traversal
*/

struct tnode *insert_element(int element, struct tnode *root){
    if (root==NULL){
        struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
        newnode->data = element;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }else{
        if (root->data > element){
            root->left = insert_element(element, root->left);
        }else{
            root->right = insert_element(element, root->right);
        }
    }
    return root;
}

struct tnode *inorder_pred(struct tnode *root){
    if (root->left != NULL){
        return inorder_pred(root->left);
    }
    return root;
}

struct tnode *delete_element(struct tnode *root, int element){
    if (root->data != element){
        if (root->left != NULL && root->left->data > element){
            root->left = delete_element(root->left, element);
        }else if (root->right != NULL && root->right->data < element){
            root->right = delete_element(root->right, element);
        }else{
            printf("Element doesnt exist in tree!");
        }
    }else{
        if (root->left == NULL && root->right==NULL){
            free(root);
            return NULL;
        }else if (root->left == NULL){
            free(root->right);
            return root->left;
        }else if (root->right == NULL){
            free(root->left);
            return root->right;
        }else{
            struct tnode *pred = inorder_pred(root);
            root->data = pred->data;
            pred->right = delete_element(root->right, pred->data);
        }
    }
    return root;
}

void inorder(struct tnode *root){
    if (root->left!=NULL){
        inorder(root->left);
    }
    printf(" -> %d", root->data);
    if (root->right!=NULL){
        inorder(root->right);
    }
}

void preorder(struct tnode *root){
    printf(" -> %d", root->data);
    if (root->left!=NULL){
        inorder(root->left);
    }
    if (root->right!=NULL){
        inorder(root->right);
    }
}

void postorder(struct tnode *root){
    if (root->left!=NULL){
        inorder(root->left);
    }
    if (root->right!=NULL){
        inorder(root->right);
    }
    printf(" -> %d", root->data);
}


int main(){
    while(1){
        int choice, element;
        printf("Choose:\n1. insert element\n2. delete element\n3. inorder\n4. preorder\n5. postorder\n99. exit\n\t>>");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert_element(element, root);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                delete_element(root, element);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("%d %d %d", root->data, root->left->data, root->right->data);
            case 99:
                return 0;
            default:
                printf("invalid option");
        }
    }
}