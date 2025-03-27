// Now we are going to check the array for the subarrays sum if equal to the given sum
#include<stdio.h>
#include<stdbool.h>
bool isSubSum(int arr[],int n,int sum){
    int s=0,curr=0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        while(sum<curr){
            curr-=arr[s];
            s++;
        }
        if(curr == sum) 
            return true;
    }
    return false;
}
int main(){
    int arr[10],n,sum;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the sum value that you want to check in the array");
    scanf("%d",&sum);
    if(isSubSum(arr,n,sum)){
        printf("The sum exists in the array");
    }
    else printf("The sum does not exist in the array");
    
    return 0;
}