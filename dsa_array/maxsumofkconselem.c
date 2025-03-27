// Here we are going to apply the sliding window technique in order to find the maximum sum of k consecutive elements.
// Firstly we are going to implement the naive solution of finding the maximum sum
#include<stdio.h>
#include<limits.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int maxSum(int arr[],int n,int k){
    int res=INT_MIN;
    // this condition for i is like i+k-1 because we have to find the consecutive elements sum only when there are k consecutive elements
    // available in the array. Suppose we have reached toward the end and we have only 1 element left to be reached so if we wanna do the 
    // sum of 3 consec elements then we have 1 element less to do the sum so we will leave that element as it is without doing the sum 
    // thats why we have applied this condition here.
    for(int i=0;i+k-1<n;i++){
        int currSum = 0;
        for(int j=0;j<k;j++){
            currSum+=arr[i+j];
        }
        res = max(res,currSum);
    }
    return res;
}
int main(){
    int arr[5]={1,3,4,-2,8},k,n=5;  //if k=3 then this means that the outer loop will go to 4 only not beyond that
    int result = maxSum(arr,n,k=3);
    printf("%d",result);
    return 0;
}