#include<stdio.h>
void reverse(int arr[],int low,int high){
    while(low<high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
}
void leftrotatearray(int arr[],int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
int main(){
    int n,d;
    printf("Enter the nubmer of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter d");
    scanf("%d",&d);
    leftrotatearray(arr,n,d);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}