#include<stdio.h>
#include<stdbool.h>
void leaders(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=i+1;j<n;j++){
            if(arr[i] <= arr[j]){
                flag = false;
                break;
            }
        }
        if(flag) printf("%d ",arr[i]);
    }
}
// but there is one more approcch for the same purpose of finding the leaders
void leadersApproach2(int arr[],int n){
    int leader = arr[n-1];
    printf("%d ",leader);
    for(int i = n-2;i>=0;i--){
        if(leader < arr[i]){
            leader = arr[i];
            printf("%d ",leader);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    leaders(arr,n);
    printf("\n");
    leadersApproach2(arr,n);
    return 0;
}