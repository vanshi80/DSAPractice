#include<stdio.h>
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int maxDiff(int arr[],int n){
    int res = arr[1]-arr[0],minValue = arr[0];
    for(int i=1;i<n;i++){
        res = max(res,arr[i]-minValue);
        minValue = min(minValue,arr[i]);
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int diff = maxDiff(arr,n);
    printf("%d",diff);
    return 0;
}