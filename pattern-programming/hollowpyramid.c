//     *
//    * *
//   *   *
//  *     *
// * * * * *
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        for(int k=0;k<i+1;k++){
            // now we have to apply certain condition to make it a hollow pyramid
            if(k==0||i==n-1||k==(i+1-1)){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}