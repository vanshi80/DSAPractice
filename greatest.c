// write a program to enter three numbers and print greater number
#include<stdio.h>
#include<conio.h>
void main(){
    int n1,n2,n3;
    printf("Enter three numbers");
    scanf("%d %d %d", &n1, &n2, &n3);
    if(n1>n2 && n1>n3){
        printf("n1 is greatest");
    }
    // we are not going to check for n2 and n1 bcz this check is made when n1 was not proved greatest
    else if(n2>n3){
        printf("n2 is greatest");
    }
    else{
        printf("n3 is greatest");
    }
    getch();
}