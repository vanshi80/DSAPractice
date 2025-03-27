// This program involves moving all 0s to end
#include<stdio.h>
int main(){
    int n;
    printf("Enter the nubmer of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            int temp = arr[i];
            arr[i]= arr[count];
            arr[count] = temp;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}