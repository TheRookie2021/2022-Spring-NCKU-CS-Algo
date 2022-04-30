#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int num=100;
    srand(time(NULL));
    cout << num / 2 << " " << num / 2 << endl;
    for(int i=0;i<num/2;i++){
        cout << i<<" "<<rand()%200<<endl;
    }
    for(int i=0;i<num/2;i++){
        cout << i<<" "<<rand()%200<<endl;
    }
    
    return 0;
}