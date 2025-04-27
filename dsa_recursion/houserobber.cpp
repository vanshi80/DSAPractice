#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int robber(vector<int>arr,int index){
    if(index >= arr.size()){
        return 0;
    }
    // if he does robbery in house at ith index 
    int option1 = arr[index] + robber(arr,index+2);
    // if he does not rob in house at ith index and leave it
    int option2 = 0 + robber(arr,index+1);
    return max(option1,option2);
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    // We have to determine the total money a robber could rob from the given array 1,2,3,5, is the money and 4 houses are there and the 
    // robber can not rob in two adjacent houses
    cout<<"Maximum money robber could rob: "<< robber(arr,0)<<endl;
    return 0;
}