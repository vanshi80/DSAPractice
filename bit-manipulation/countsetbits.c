#include<stdio.h>
int countsetBits(int n){
    int count=0;
    while(n!=0){
        if(n&1==1){
            count++;
        };
        n>>=1;
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int count = countsetBits(n);
    printf("The number of set bits are %d\n",count);
    return 0;
}