#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, string> Num_Name;
bool cmp(Num_Name a, Num_Name b){
    if(a.first>b.first)
        return true;
    if(a.first==b.first &&a.second < b.second)
        return true;
        
    return false;
    
}
int main(){
    int n,k;
    string str;
    map<string,int> statistic;
    // set<string> s;
    vector<Num_Name> vec;
    cin >>n>>k;
    for(int i=0;i<n;i++){
        cin>>str;
        if (statistic.find(str) != statistic.end())
        {
            statistic.find(str)->second++;
        }
        else
        {
            statistic.insert(pair<string, int>(str, 1));
        }
    }
    int j=0;
    map<string,int> ::iterator itr;
    for( itr=statistic.begin();itr!=statistic.end();itr++){
         vec.push_back(Num_Name(itr->second, itr->first));
    }
    sort(vec.begin(),vec.end(),cmp);
    cout<<vec[k-1].second;
//bug: 另外，如果有2種調酒杯數相同，則名稱字典序較小的調酒排名會比較前面。
    return 0;
}