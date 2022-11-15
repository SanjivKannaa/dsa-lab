#include<stdio.h>



void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void insertion_sort(int a[], int n){
    int i, j, key;
    for (i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while (j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

void main(){
    int a[10] = {1, 3, 2, 8, 9, 5, 7, 6, 4, 0};
    int n = 10;
    insertion_sort(a, n);
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }
}