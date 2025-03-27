#include<stdio.h>
int countSetBits(int n){
    int count=0;
    while(n>0){
        n=(n&(n-1));
        count++;
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int count = countSetBits(n);
    printf("The number of set bits are %d\n",count);
    return 0;
}