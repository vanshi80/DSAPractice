#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i){
    // We are creating the max heap whihc means the the parent node is the larger than its childrenn node at every level 
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        // WE have to make a visit once again to check if tree is heapified or not after swapping
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[], int n){
    // firstly heapify the array and create a min tree out of it
    // suppose the array given to us is the heap tree and for every node we have its left and right child at specific indexes now we
    // have to move to the last non leaf node and compare it with its left and right children by heapify function and first non leaf
    // element starts from n/2-1 in the array of heap tree
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);   //we have to heapify at the ith index and the lenght of the heap tree is n at this time
    }
    // now comes the sorting logic ->the element at index 0 is swapped with the right most leaf node which is at last index initially and then heapify the tree
    for(int i = n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        // we have to heapify the root node and our tree length is now i only
        heapify(arr,i,0);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

    // now we have to convert our array into the heap tree 
    return 0;
}