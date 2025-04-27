// here we have to parition the array in two parts such that the sum of both the parts are same
// and if we get such partitions then return true otherwise false
#include<stdio.h>
#include<iostream>
using namespace std;
bool ispartitionpossible(int arr[],int n,int k){
    if(k == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(arr[n-1] > k){
        return ispartitionpossible(arr,n-1,k);
    }
    return ispartitionpossible(arr,n-1,k) || ispartitionpossible(arr,n-1,k - arr[n-1]);
}
int main(){
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int totalsum = 0;
    for(int i= 0;i<n;i++){
        totalsum += arr[i];
    }
    if(ispartitionpossible(arr,n,totalsum/2)){
        cout<<"The partition is possible.\n";
    }
    else {
        cout<<"The partition is not possible\n";
    }
    return 0;
}