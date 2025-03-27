#include<stdio.h>
void reverseanarray(int arr[],int n){
    int low = 0;
    int high = n-1;
    while (low<high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    
}
int main(){
    int n;
    printf("Enter the nubmer of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverseanarray(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}