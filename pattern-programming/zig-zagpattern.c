// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     for(int i=0;i<2*n-1;i++){
//         if(i<n){

//         for(int j=0;j<n-i-1;j++){
//             printf("_");
//         }
//         for(int j=0;j<2*i+1;j++){
//             if(j==0||j==2*i)
//                 printf("*");
//             else{
//                 printf("_");
//             }
//         }
//         if(i!=n)printf("\n");
//         }
//         else{
//         // printf("printing next row");
//         for(int j=0;j<=i-n;j++){
//             printf("_");
//         }
//         for(int j=0;j<2*n-i ;j++){
//             if(j==0||j==(2*n-i)){
//                 printf("*");
//             }
//             else printf("_");
//         }
//         printf("\n");

//         }
//     }
//     return 0;
// }
#include <stdio.h>

int main() {
    int n = 4;

    // First outer loop to iterator through each row
    for (int i = 0; i < 2 * n - 1; i++) {
        
        // Assigning values to the comparator according to
        // the row number
        int comp;
        if (i < n) comp = 2 * (n - i) - 1;
        else comp = 2 * (i - n + 1) + 1;

        // First inner loop to print leading whitespaces
        for (int j = 0; j < comp; j++)
            printf(" ");

        // Second inner loop to print star * and inner
        // whitespaces
        for (int k = 0; k < 2 * n - comp; k++) {
            if (k == 0 || k == 2 * n - comp - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    
    return 0;
}