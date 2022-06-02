#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
    int n;
    srand(time(NULL));
    cin>>n;
    cout<<n<<endl;
    for(int i =0;i<n;i++){
        cout<<(rand()%20-10)<<" "<<(rand()%20-10)<<endl;
    }
    return 0;
}