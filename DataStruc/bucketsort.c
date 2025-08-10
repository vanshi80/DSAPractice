#include<stdio.h>
int max_element(int arr[], int n){
    int max = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
void bucketsort(int arr[], int n){
    // first find out the maximum of array to find the bucket size
    int max = max_element(arr, n);
    int bucket[max+1]; //max+1 becuae the array might contain the 0 also so that will require the indexes to be from 0 to max
    // initialize the buckets to zero
    for(int i = 0;i<=max;i++){
        bucket[i] = 0;
    }
    for(int i = 0;i<n;i++){
        bucket[arr[i]]++;
    }

    int j = 0;
    for(int i = 0;i<=max;i++){
        while(bucket[i]>0){
            arr[j++] = i;

            bucket[i]--;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bucketsort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}