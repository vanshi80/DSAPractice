// Here we could have two odd occuring numbers in the arra and we have to find them
#include<stdio.h>
void twooddOcurringNo(int arr[],int n){
    int xor=0;
    for(int i=0;i<n;i++){
        xor = xor^arr[i];
    }
    // now we will find the rightmost set bit in xor result
    xor = xor & (~(xor-1));
    int res1=0,res2=0;
    // then we will perform the AND of rightmost set bit with all array elements if it returns 1 then xor them separately and 0 then 
    // separately then the two results are the numbers which are odd occuring.
    for(int i=0;i<n;i++){
        if(xor & arr[i]){
            res1 = res1 ^ arr[i];
        }
        else{
            res2 = res2 ^ arr[i];
        }
    }
    printf("The two odd occuring numbers are %d and %d\n",res1,res2);
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
    twooddOcurringNo(arr,n);
    return 0;
}