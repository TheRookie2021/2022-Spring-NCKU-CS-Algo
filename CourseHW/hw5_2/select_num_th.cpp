#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,string> Num_Name;
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
        // vec.push_back(Num_Name(i.second, i.first));
        if(j==statistic.size()-k+1){
            cout << itr->first;
            break;
        }
        j++;
    }
//bug: 另外，如果有2種調酒杯數相同，則名稱字典序較小的調酒排名會比較前面。
    return 0;
}