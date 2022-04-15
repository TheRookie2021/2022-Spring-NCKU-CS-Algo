#include<iostream>
using namespace std;
int main(){
    int max=5;
    for(int i=0;i<max*2-1;i++){
        if(i<max){
            for(int j=0;j<i+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }else{
            for(int j=0;j<(2*max-i)-1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }

    return 0;
}