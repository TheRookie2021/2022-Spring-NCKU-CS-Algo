//*** see hw7-1 ***//

#include<iostream>
using namespace std;
int max(int a,int b){
    return (a > b) ? a : b;
}
// assume the index is (the weight of item) - 1, the entry stores the value
// , and w is the limited weight 
int knapsack_01(int items_values[], int w){
    /////////////////////////////////////////////////////
    //  memo[size][weight]
    //      W=0, 1, 2, ..., w
    // i=0
    // i=1
    // i=2
    // i=...
    /////////////////////////////////////////////////////
    int size=sizeof(items_values)/sizeof(items_values[0]);
    int memo[size+1][w];// to fill in the opt value
    for(int i =0;i<size+1;i++)
        for(int j=0;j<w+1;j++)
            memo[i][j] = 0;
    // bottom-up: Opt(W(i+1))=Opt(max(W(i+1-w[i])+V(i+1),W(i)))
    for(int i =1;i<size+1;i++){
        for(int j=1;j<w+1;j++)
        {
            if (j >= i)
                memo[i][j] = max(items_values[i - 1] + memo[i - 1][j - (i - 1)], memo[i - 1][j]);
                //items_values[i - 1] + memo[i - 1][j - i]: items_values[i - 1], i-1 because entry start at 0 
            else
                memo[i][j]=memo[i-1][j];
        }
    }
}


int main(){
    int n,w;
    cin >> n >> w;
    int items_values[n];
    for(int i =0;i<n;i++)
        cin>>items_values[i];
    
    return 0;
}