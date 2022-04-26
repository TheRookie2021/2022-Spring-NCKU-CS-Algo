#include <iostream>
// #include<stdlib.h>
using namespace std;
long int  Fibo_memo(int n, long int  f[]){
    // end condition: it is already traversed
    if (f[n] != -1)
        return f[n];
    // recursive step: not yet traversed
    f[n]=Fibo_memo(n-1,f)+ Fibo_memo(n-2,f);
    return f[n]; 
}
long int Fibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;

    long int  f[n+1];
    f[0] = 0;
    f[1] = 1;

    // intialize
    for(int i =2;i<n+1;i++){
        f[i] = -1;
    }
    return Fibo_memo(n, f);
}

int main(){
    int n=100;
    cout<<Fibo(n)<<endl;


    return 0;
}