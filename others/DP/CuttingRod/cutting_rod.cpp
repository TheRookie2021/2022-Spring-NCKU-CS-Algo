#include <iostream>
using namespace std;
int cuttingRod_MEMO(int table[], int length, int memo[]){
    if (memo[length] != -1)
        return memo[length];
    int q = -1;
    for (int i = 1; i <= length; i++)
        q = (table[i] + cuttingRod_MEMO(table, length - i, memo) > q) ? table[i] + cuttingRod_MEMO(table, length - i, memo) : q;
    memo[length]=q;
    cout<<q<<" ";
    return q;
}

int cuttingRod(int table[], int length){
    int memo[length+1];
    for (int i = 1; i <= length; i++)
        memo[i]=-1;
    memo[0]=0;
    return cuttingRod_MEMO(table,length,memo);
}


int main(){
    int n;
    cin>>n;
    int table[n+1];
    for(int i =1;i<n+1;i++)
        cin>>table[i];

    // cout << 
    cuttingRod(table, n);

    return 0;
}