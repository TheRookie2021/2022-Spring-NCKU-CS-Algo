#include<iostream>
using namespace std;

void fun_ref(int & x){
    
    x+=10;

}

void fun_no_ref(int x){
    x += 10;
}

int main(){
    int x=1;
    cout<<"x: "<<x<<endl;
    fun_ref(x);
    cout<<"func ref x: "<<x<<endl;
    x=1;
    
    cout<<"x: "<<x<<endl;
    fun_no_ref(x);
    cout<<"func no ref x: "<<x<<endl;
    

    return 0;
}