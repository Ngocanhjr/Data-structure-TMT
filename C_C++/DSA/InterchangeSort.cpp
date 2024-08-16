#include <stdio.h>

void interchangeSort(int a[], int n);
void swap (int *a, int *b);
void getArray ( int a[], int n);
int main (){
    int arr[] = {2,5,7,3,2,1,8};
    int x = sizeof(arr)/sizeof(arr[0]);
    printf("so luong phan tu: %d\n",x);
    getArray(arr,x);
    interchangeSort(arr,x);
//   int a = 1, b=2;
//    swap(&a,&b);
//    printf("%d %d", a, b);
    printf("\n");
    getArray(arr, x);
}
void swap ( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void interchangeSort (int a[], int n){
    for ( int i = 0; i < n - 1; i++){
        for ( int j = i + 1; j < n; j++){
            if (a[j]<a[i]){
                swap(&a[i],&a[j]);
            }
        }
    }
}
void getArray(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}