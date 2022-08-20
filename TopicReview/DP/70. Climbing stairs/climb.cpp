#include<iostream>
using namespace std;
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?

// top down or bottom up?
// td: recursive
// bu: iterative

// n=0: 0
// n=1: 1
// n=2: 2
// n=3: 3 
    // 1 1 1
    // 1 2
    // 2 1
// n=4: 5
    // 1 1 1 1
    // 1 1 2
    // 1 2 1
    // 2 1 1
    // 2 2
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        
        int memo[n+1];
        memo[0]=0;
        memo[1]=1;
        memo[2]=2;

        for(int i =3;i<n+1;i++)
            memo[i]=memo[i-1]+memo[i-2];
        return memo[n];
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    cout<<sol.climbStairs(n);
    
    return 0;

}