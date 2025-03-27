// for finding out the number of bits to be flipped we will xor two numbers and then count the set bits becaue the different bits will show
// 1 in the xor result so the those will be the bits to be flipped
#include<stdio.h>
int countsetBits(int n){
    int count=0;
    while(n!=0){
        n = n & (n-1);
        count++;
    }
    return count;
}
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int count = countsetBits(a^b);
    printf("The number of bits to be flipped to convert %d to %d are %d\n",a,b,count);
    return 0;
}