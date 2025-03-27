#include<stdio.h>
int main(){
    char dept;
    int sec;  //memory space is created of integer type
    printf("Enter the dept");
    scanf("%c",&dept);
    if(dept == 'm' || 'M' ){
        printf("Enter the section");
        scanf("%d",&sec);
        if(sec == 3){
            printf("welcome to section 3 of mca dept");
        }
        else{
            printf("You do not belong to section 3 of mca");
        }
    }
    else{
        printf("you do not belong to mca dept");
    }
    return 0;
}