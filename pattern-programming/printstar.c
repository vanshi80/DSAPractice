#include<stdio.h>
int main(){
    for(int i=0;i<4;i++){
        for(int j=i;j<4-1;j++){
            printf("  ");
        }
        for(int k=0;k<=2*i+1;k++){
            if(k%2==0) printf(" * ");
            else printf("  ");
        }
        printf("\n");
    }
    return 0;
}