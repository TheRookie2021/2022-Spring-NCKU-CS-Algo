#include<iostream>
#include<string>
#include<vector>

#include <typeinfo>
using namespace std;
typedef pair<double,string> Concen_Name;
int main(){
    int n,kth;
    string tempstr;
    cin >> n >> kth;
    vector<Concen_Name> vec(n);
    double ta,tb,tc;
    for(auto i:vec){
        // cout<<typeid(i).name()<<endl;
        cin>>ta>>tb>>tc>>tempstr;
        cout<<i.first<<endl;
        
        i.first=tc/(ta+tb+tc);
        cout<<i.first<<endl;
        i.second=tempstr;
        cout<<i.second<<endl;
    }
    
    // for(auto i:vec){
    //     cout<<i.first<<i.second<<endl;
    // }
     for(int i=0;i<n;i++){
        cout<<vec[i].first<<vec[i].second<<endl;
    }
    return 0;
}