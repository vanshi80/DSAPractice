#include<stdio.h>
int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    // create a mask
    int mask = (1<<(k-1));
    // if n&mask returns some non zero value then the kth bit is set otherwise not
    if((n&mask)){
        printf("kth bit is set");
    }else{
        printf("kth bit is not set");
    }
    return 0;
}