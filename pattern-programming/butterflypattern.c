// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n-1;i++){
        if(i<n){
        for(int j =0;j<i+1;j++){
            printf("*");
        }
        for(int j =0;j<2*n-2*i-2;j++){
            printf(" ");
        }
        for(int j =0;j<i+1;j++){
            printf("*");
        }
        printf("\n");

        }
        else{
            for(int j=1;j<2*n-i;j++){
                printf("*");
            } 
            for(int j=0;j<2*i-2*n+2;j++){
                printf(" ");
            } 
            for(int j=1;j<2*n-i;j++){
                printf("*");
            } 
            printf("\n");
        }

    }
    return 0;
}