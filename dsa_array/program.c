// Here we have to compute the sum of elements of an array between the given range
// like array is 1,2,3,4,5,6 and we have to getSum(0,2)=1+2+3=6 is the sum
// we could do this through two ways 
// int getSum(int arr[],int l,int r){ //l to r represent the range,element bw which we want to sum
//     int res=0;
//     for(int i=l;i<=r;i++){
//         res+=arr[i];
//     }
//     return res;
// }
// but through the above method the loop to calculate the sum will run every time we call getSum
// NOW there is another effecient solution to create an array that contains the sum of the consecutive elements in the array like
// for array 1,2,3,4,5 its pSum array would contain =1,1+2,1+2+3,1+2+3+4,1+2+3+4+5 so if we need to find the sum of elements from indx 
// 2 to 4 then we will do pSum[4]-pSum[1] will give us the required sum so no matter how many times we call this getSum function 
// for different values we will be having our sum with us
#include<stdio.h>
int pSumCalc(int arr[],int n){
    int pSum[n];
    pSum[0]=arr[0];
    for(int i=1;i<n;i++){
        pSum[i]=arr[i]+pSum[i-1];
    }
    return pSum;
}
int getSum(int pSum[],int l,int r){
    if(l==0)
        return pSum[r];
    return pSum[r]-pSum[l-1];
}
int main(){
    int arr[10],pSum[10],n;
    printf("Enter the array size");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    pSum[n] = pSumCalc(arr,n);
    getSum(pSum,2,4);
    return 0;
}