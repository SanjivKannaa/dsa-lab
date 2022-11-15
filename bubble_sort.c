#include<stdio.h>



void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubble_sort(int a[], int n){
    int i, j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void main(){
    int a[10] = {1, 3, 2, 8, 9, 5, 7, 6, 4, 0};
    int n = 10;
    bubble_sort(a, n);
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }
}