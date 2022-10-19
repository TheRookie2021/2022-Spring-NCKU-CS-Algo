#include<iostream>
using namespace std;

int  main(){
    int  n;
    cin>>n;
    unsigned long int  memo[n+1];
    memo[0]=0;
    memo[1]=1;
    memo[2]=2;
    if(n>=3)
        for (int i = 3; i <= n; i++)
        {
            memo[i] = memo[i - 1] + memo[i -2];
        }
    cout<<memo[n];

    return 0;
}