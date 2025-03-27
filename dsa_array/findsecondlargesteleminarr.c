#include<stdio.h>
int findSecondLargestElement(int arr[],int n){
    int largest = arr[0];
    int secondlargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            secondlargest = largest;
            largest = arr[i];
        }
        if(arr[i]<largest && arr[i]>secondlargest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
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
    int secondlargest = findSecondLargestElement(arr,n);
    printf("The second largest element is %d\n",secondlargest);
    return 0;
}