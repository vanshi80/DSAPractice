// This algorithm is to find the majority element in the array.
#include<stdio.h>
int findTheMajority(int arr[],int n){
    int res=0,count =1;
    for(int i=1;i<n;i++){
        if(arr[res] == arr[i])
            count++;
        else count--;
        if(count == 0){
            res=i;
            count =1;
        }
    }
    printf("The %dth element is at majority\n",res);
    count = 0;
    for(int i=0;i<n;i++){
        if(arr[res] == arr[i]){
            count++;
        }
    }
    if(count>n/2){
        return res;
    }
    return -1;
}
int main(){
    int arr[5]={4,4,4,4,3};
    int n=5;
    int res = findTheMajority(arr,n);
    printf("%d\n",arr[res]);
    return 0;
}