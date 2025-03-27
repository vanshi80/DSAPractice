#include<stdio.h>
int findXor2(int n){
    int k=n%4;
    if(k==0)
        return n;
    else if(k==1)
        return 1;
    else if(k==2)
        return n+1;
    else if(k==3)
        return 0;
}
int findXor(int l,int r){
    return findXor2(l-1)^findXor2(r);
}
int main(){
    int l=4,r=8;
    printf("Xor betwee %d and %d is %d\n",l,r,findXor(l,r));
    return 0;
}