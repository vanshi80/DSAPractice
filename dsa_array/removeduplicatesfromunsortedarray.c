// here in this program we will remove duplicates from unsorted array
#include<stdio.h>
#include<stdbool.h>
#define max 1001
// her we are going to create an array and setting its values to false initially and for value value seeen we will set its corresponding
// value to true
int removeduplicates(int arr[],int n){
    bool seen[max] = {false};
    int newLength = 0;
    for(int i=0;i<n;i++){
        if(!seen[arr[i]]){
            seen[arr[i]]=true;
            arr[newLength] = arr[i];
            newLength++;
        }
    }
    return newLength;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int newl=removeduplicates(arr,n);
    for(int i=0;i<newl;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}