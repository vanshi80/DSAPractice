// here we have to count all the subsets whose sum equals the target sum
#include<stdio.h>
#include<iostream>
using namespace std;
int countsubset(int arr[],int n, int k){
    // agr n aur k dono zero hojaye iska mtlb we found one subset other n 0 hai but sum nhi to return 0
    if(n == 0){
        return k == 0?1:0;
    }
    if(k < arr[n-1]){
        // Exclusion case
        return countsubset(arr,n-1,k);
    }
    // exclusion plus inclusion result
    return countsubset(arr,n-1,k)+countsubset(arr,n-1,k-arr[n-1]);
}
int main(){
    int arr[] = {3,4,2,5,7};  //{3,4,2} {4,5} {2,7} these are the subsets that sum up to 9
    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 9;
    cout<<"The total subsets whose sum equals "<< targetSum<<" are"<<countsubset(arr,n,targetSum);
    return 0;
}