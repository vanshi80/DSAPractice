#include<stdio.h>
int main(){
    int a,b,flips;
    scanf("%d",&a);
    scanf("%d",&b);
    while(a !=0 && b!=0){
        int t1 = (a&1);
        int t2 = (b&1);
        if(t1!=t2){
            flips++;
        }
        a=a>>1;
        b=b>>1;
    }
    printf("The number of bits to be flipped are %d",flips);
    return 0;
    
}