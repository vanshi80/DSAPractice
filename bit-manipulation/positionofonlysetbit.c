// in this program we will find out the position of only set bit or 1 in the binary number so to do this first of all we will check 
// whether the number is a power of 2 or not because then only it contains a single and then we will 
#include<stdio.h>
int powerofTwo(int n){
    return (n && ((n&(n-1))==0));
}
int findonlysetbit(int n){
    int pos=1;
    int i=1;
    while((i&n) == 0){
        i=i<<1;
        pos++;
    }
    return pos;
}
int main(){
    int n,pos;
    scanf("%d",&n);
    int result = powerofTwo(n);
    // printf("result of powerof two function %d",result);
    if(powerofTwo(n)){
        pos = findonlysetbit(n);
        printf("The position of the only set bit is %d from right\n",pos);
    }
    else{
        printf("This number contains more than one set bit\n");
    }
    return 0;
}