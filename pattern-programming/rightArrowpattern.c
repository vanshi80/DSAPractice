#include<stdio.h>
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
int main(){
    int n;
    scanf("%d",&n);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<n-i;j++){
    //         printf("*");
    //     }

    //     printf("\n");
    // }
    // we can optimise this using the following way
    for(int i=0;i<2*n-1;i++){
        int cond;
        if(i<n){
            cond = i+1;
        }else{
            cond = 2*n-i-1;
        }
        for(int j=0;j<cond;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}