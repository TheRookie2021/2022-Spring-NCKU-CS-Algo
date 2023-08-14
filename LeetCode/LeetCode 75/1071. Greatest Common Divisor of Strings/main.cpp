#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
// practice the usage of string class
string gcdOfStrings(string str1, string str2)
{
    if (str1[0] != str2[0])
        return "";
    
    string gcd;
    unordered_set<char> s_str1,s_str2;
    for(int i =0; i<str1.size();i++){
        s_str1.insert(str1[i]);
    }
    for(int i =0; i<str2.size();i++){
        s_str1.insert(str2[i]);
        
    }
    if(s_str1==s_str2){
        if(str1.size()>str2.size()){
            for (auto it = s_str1.begin(); it != s_str1.end(); it++)
            {
                gcd.append(*it);
            }
        }else{

        }
        return gcd;
    }else return"";
}

int main(){
    
    return 0;
}