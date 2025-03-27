#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,d,f_dig,l_dig;
    // cout<<"Enter the number of digits :";
    // cin>>d;
    cout<<"Enter the number";
    cin>>n;
    f_dig=n;
    while(f_dig>=10){
        f_dig /=10;
    }
    cout<<f_dig;
    // f_dig = n/(pow(10,d-1));
    l_dig = n%10;
    cout<<"The sum of first and last digit of the number entered by you is: "<<f_dig+l_dig<<endl;
    return 0;


}