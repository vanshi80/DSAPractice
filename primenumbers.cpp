#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int s,e,flag=0,count=0;
    cout<<"Enter the starting and the ending range for finding the prime numbers in between: ";
    cin>>s>>e;
    for(int i=s+1;i<e;i++){
        // cout<<i<<endl;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                // cout<<"Not prime:"<<i<<endl;
                flag = 1;
                break;
            }
            flag =0;
        }
        
        if(flag == 0){
            // cout<<"primes:";
            cout<<i<<endl ;
            count++;
        }
    }
    cout<<"Total prime numbers between "<< e<<" and "<< s<<" are: "<<count<<endl;
    return 0;
}