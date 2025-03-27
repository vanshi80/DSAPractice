// Here we are going to find the maximum subarray sum through Kadane's alog
#include<stdio.h>
int maximumSubarraySum(int arr[],int n){
    int maxSum = 0;
    int currSum =0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum = currSum;
        }
        if(currSum<0){
            currSum =0;
        }
    }
    return maxSum;
}
int main(){
    int arr[]={-2,-3,4,1,6,-1,-3};
    int n = 7;
    int res=  maximumSubarraySum(arr,n);
    printf("%d\n",res);
    return 0;
}