#include<iostream>
#include<string>
#include<vector>
#include <typeinfo>
using namespace std;
typedef pair<double,string> Concen_Name;
int main(){
    int n[5]={10,11,12,12,15};
    for (auto i : n){
        //here, i represets n[i]
        cout<<typeid(n).name()<<endl;

        if(i==2)break;//no use
        if(i==12)break;//work
        
        cout<<i<<" ";
    }
    return 0;
}