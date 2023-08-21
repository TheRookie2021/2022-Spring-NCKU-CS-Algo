#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
// practice the usage of string class
string gcdOfStrings(string str1, string str2)
{
    if (str1[0] != str2[0])
        return "";
    
    string gcd;
    unordered_set<string> s_str1,s_str2;
    for(int i =0; i<str1.size();i++){
        s_str1.insert(str1.substr(i,1));
    }
    for(int i =0; i<str2.size();i++){
        s_str2.insert(str2.substr(i,1));
        
    }
    for (const std::string& x: s_str1) std::cout << " " << x;
    cout<<endl;
    if(s_str1==s_str2){
        if(str1.size()>str2.size()){
            for (auto it = s_str1.begin(); it != s_str1.end(); it++)
            {
                // cout<<*it;
                gcd.append(*it);
            }
        }else{
            for (auto it = s_str2.begin(); it != s_str2.end(); it++)
            {
                // cout<<*it;
                gcd.append(*it);
            }
        }
        reverse(gcd.begin(),gcd.end());
        return gcd;
    }else return"";
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