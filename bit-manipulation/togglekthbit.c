#include<stdio.h>
int togglekbit(int n,int k){
    return n ^(1<<(k-1));
}
int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int N = togglekbit(n,k);
    printf("After toggling number becomes %d\n",N);
    return 0;
}


 