#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int evenOddSubarray(int arr[],int n){
    int res=1,curr=1;
    for(int i=1;i<n;i++){
        if(arr[i]%2 == 0 && arr[i-1]%2!=0 || arr[i]%2 != 0 && arr[i-1]%2==0){
            curr++;
            res = max(res,curr);
        }
        else{
            curr=1;
        }
    }
    return res;
}
int main(){
    int arr[]={10,11,10,11,11,11,11};
    int n = 7;
    int res =  evenOddSubarray(arr,n);
    printf("%d\n",res);
    return 0;
}