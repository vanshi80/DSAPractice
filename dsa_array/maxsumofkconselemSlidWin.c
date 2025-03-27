// now the same program for finding the maximum sum of k consecutive elements is done with the help of sliding window technique
// {1,2 ,4,3,5,6,7,8,9}
// suppose we have k=4 then first window = 1+2+4+3 then 
// second window 1+2+4+3 +5-1 -->so basically we are adding one new element and deleting the first element of the previos window 
#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int maxSum(int arr[],int n,int k){
    int currSum=0,res;
    for(int i=0;i<k;i++){
        currSum+=arr[i];
    }
    res=currSum;
    for(int i=k;i<n;i++){
        currSum= currSum + arr[i] - arr[i-k];   //deleting the first element of the previous window and adding one another element from ahead
        res = max(res,currSum);
    }
    // printf("The maximum sum is %d",res);
    return res;
}
int main(){
    int arr[10],n,k,sum;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number of elements whose maximum sum you want to find out");
    scanf("%d",&k);
    sum = maxSum(arr,n,k);
    printf("The maximum sum of %d consecutive elements is %d",k,sum);
    return 0;
}

