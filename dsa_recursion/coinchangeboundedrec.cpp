// we are given denominations of coins and we have to tell how can we take up the coins so as to get the sum given
#include<stdio.h>
#include<iostream>
using namespace std;
int getcoincombin(int arr[], int n, int k){
    if(k == 0){
        return 1;
    }
    if(k < 0){
        return 0;
    }
    if(n == 0){
        return 0;
    }
    return getcoincombin(arr, n-1,k) + getcoincombin(arr,n-1,k - arr[n-1]);
}
int main(){
    int arr[] = {1,2,3,2}; 
    int sum = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The total combinations of the coins to get the sum "<<sum<<" are "<<getcoincombin(arr,n,sum)<<endl;
    return 0;
}
