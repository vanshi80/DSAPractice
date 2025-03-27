// wap to enter any year and check wheter it is a leap year or not
// year is divisible by 4  but year should not divided by 100 or it must be divisble by 400
// we have to check if the year is divisible by 4 or 400 and not by 100
#include<stdio.h>
int main(){
    long year;
    printf("enter the year");
    scanf("%ld",&year);
    if((year % 4 == 0 &&  year % 100 != 0 ) || year % 400 == 0){
        printf("Year entered is leap year");
    }
    else{
        printf("it is not a leap year");
    }
    return 0;
}