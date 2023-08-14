#include<iostream>
#include<string>
using namespace std;
// practice the usage of string class

string mergeAlternately(string word1, string word2) {
        string str;
        int a=0,b=0;
        for (int i = 0; i < (word1.size() + word2.size()+1); i++)
        {
            if(i%2==0){
                if(word1.size()>=a)
                    str.append(word1, a++, 1);
            }else{
                if(word2.size()>=b)
                    str.append(word2, b++, 1);
            }
        }
        if(word1.size()>word2.size()){
            str.append(word1,a);
        }
        else if(word1.size()<word2.size()){
            str.append(word2,b);
        }
        return str;
}

int main(){
    string w1,w2;
    cin>>w1>>w2;
    cout << mergeAlternately(w1, w2);
    return 0;
}