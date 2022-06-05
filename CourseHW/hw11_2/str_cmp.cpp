#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

int main(){
    std::string str1("apple");
    std::string str2("apdde");
    for(int i =0;i<str1.size();i++){
        if (str1[i] != str2[i])
            cout << 0;
        else
            cout << 1;
    }
    return 0;
}