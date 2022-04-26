#include <iostream>
using namespace std;

long int Fibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;

    long int  f[n+1];
    f[0] = 0;
    f[1] = 1;

    // intialize
    for(int i =2;i<n+1;i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(){
    int n = 10;
    cout<<Fibo(n)<<endl;



    return 0;
}