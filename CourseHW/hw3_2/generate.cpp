#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
    int x=256;
    cout<<x<<endl;
    srand(time(NULL));
    for(int i=0;i<x;i++){
        cout<<rand()%101<<" ";
    }

    return 0;
}