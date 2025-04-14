// this problem include the merge sort at every merge sort step of partioning and then merging back we coun thte no of partions 
// return them back inversions means pair of arr[i],arr[j] such than i<j and arr[i]>arr[j]
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int merge(vector<int>&arr,int st,int mid,int end){
    int i = st,j = mid+1, idx = 0,inversions =0;
    vector<int>temp;
    
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            inversions+=mid-i+1;
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= end) {
        temp.push_back(arr[j++]);
    }
    for(int idx = 0;idx<temp.size();idx++){
        arr[st+idx] = temp[idx];
    }
    return inversions;
}
int mergesort(vector<int>&arr,int st,int end){
    int mid = st+(end - st)/2;
    // keep breaking the array from mid until we get the single element left in the partition
    if(st<end){
        // Left partition
        int leftinversions = mergesort(arr,st,mid);
        // right partition
        int rightinversions = mergesort(arr,mid+1,end);
        int inversions = merge(arr,st,mid,end);

        return leftinversions+rightinversions+inversions;
    }
    return 0;
}
int main(){
    vector<int>arr = {6,3,5,2,7};
    int inversions = mergesort(arr,0,arr.size()-1);
    for(int a:arr){
        cout<<a <<" ";
    }
    cout<<"The number of inversions in this array are "<<inversions<<endl;
    return 0;
}