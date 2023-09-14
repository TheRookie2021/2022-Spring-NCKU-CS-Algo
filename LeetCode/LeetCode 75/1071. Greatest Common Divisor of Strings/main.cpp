#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
// practice the usage of string class
string gcdOfStrings(string str1, string str2)
{
    // if (str1[0] != str2[0])
    //     return "";
    
    string gcd="";
    set<string> s_str1,s_str2;// not working,  
    // unordered_set are not sorted in any particular order, but organized into buckets depending on their hash values to allow for fast access

    for(int i =0; i<str1.size();i++){
        s_str1.insert(str1.substr(i,1));
    }
    for(int i =0; i<str2.size();i++){
        s_str2.insert(str2.substr(i,1));
        
    }
    vector<string> intersect_str(max(str1.size(),str2.size()));
    auto it= set_intersection(s_str1.begin(),s_str1.end(),s_str2.begin(),s_str2.end(),intersect_str.begin());
    intersect_str.resize(it - intersect_str.begin());
    // if(s_str1==s_str2)
    for (int i = 0; i < intersect_str.size(); i++) // we know the size of gcd by set container
    {
        if (str1[i] == str2[i]) // check the order of gcd (len of gcd must <= len of set)
        {
            gcd.append(str1.substr(i, 1));
        }
        else
            break;
    }
    return gcd;
}

int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        if(str1=="q")
            break;
    cout<<gcdOfStrings(str1,str2)<<endl;
    }
    return 0;
}