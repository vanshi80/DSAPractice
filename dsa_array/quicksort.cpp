#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int start,int end){
    int idx = start-1;//this will be incremented to swap the elements smaller than the pivot to where the 
    // incremented index is pointing
    int pivot = arr[end]; //last element is the pivot
    for(int i = start;i<end;i++){
        if(pivot>=arr[i]){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++; //this is the index where are pivot will be stored
    swap(arr[idx],arr[end]);
    return idx;
}
void quicksort(vector<int>&arr,int start,int end){
    if(start<end){
        int pivIdx = partition(arr,start,end);
        // now make a call for the left and right partitions
        quicksort(arr,start,pivIdx-1);
        quicksort(arr,pivIdx+1,end);
    }
}
int main(){
    vector<int>arr = {2,0,9,56,43,89,1};
    quicksort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}