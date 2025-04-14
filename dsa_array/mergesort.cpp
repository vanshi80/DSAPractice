#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
void merge(vector<int>&arr,int st,int mid,int end){
    int i = st,j = mid+1, idx = 0;
    vector<int>temp;
    
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= end) {
        temp.push_back(arr[j++]);
    }
    // here we have to place the correct element ot its correct place andn arr[st+idx] is done bcz this merging is done to various subarrays
    for(int idx = 0;idx<temp.size();idx++){
        arr[st+idx] = temp[idx];
    }
}
void mergesort(vector<int>&arr,int st,int end){
    int mid = st+(end - st)/2;
    // keep breaking the array from mid until we get the single element left in the partition
    if(st<end){
        // Left partition
        mergesort(arr,st,mid);
        // right partition
        mergesort(arr,mid+1,end);
        // now we have two sorted arrays left with us at each backtracking step (like at last we have single single elements in left and 
        // right parti which we merged together thn similarly we moved further upwards)
        // in the same array we have our partitions made where the range of left partition is st to mid and the range of right partin is 
        // mid+1 to end
        merge(arr,st,mid,end);
    }
}
int main(){
    vector<int>arr = {3,9,1,0,54,99};
    mergesort(arr,0,arr.size()-1);
    for(int a:arr){
        cout<<a <<" ";
    }
    return 0;
}