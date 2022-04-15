#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// order: decendent order
bool cmp_decendent(int a, int b){
    if (a > b)// 大的在前
        return true;
    return false;
}

// order: ascendent order
bool cmp_ascendent(int a, int b){
    if (a < b)// 小的在前
        return true;
    return false;
}
int main(){
    vector<int> v={4,2,8,6,1,3,8,9,7};
    for (auto i : v)
        cout << i << " ";
    sort(v.begin(),v.end(),cmp_ascendent);
    cout<<endl;
    for (auto i : v)
        cout << i << " ";
    return 0;
}