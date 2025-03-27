// here we have to left rotate an array 1
#include<stdio.h>
int main(){
    int arr[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}