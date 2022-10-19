#include <iostream>
using namespace std;
char *
addstr(char * a , char * b){
    char * output;
    int size_a=a.size(),size_b=b.size();
    if(size_a>size_b){
        int sum=0;
        for(int i=0;i<size_b;i++){
            sum=atol(a[i])+atol(b[i]);
            output.push_back();
        }
    }else{

    }
}
int main()
{
    char * x,y;
    x="123";
    y="456";
    cout<<x+y;
}   