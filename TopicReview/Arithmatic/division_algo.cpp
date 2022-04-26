#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int a,b;
    int temp=0;
    cout<<"a/b=?"<<endl;
    cin >>a>>b;
    while(a>=b)
{
    a=a-b;
    temp++;
}
    cout<<"a "<<a<<", b "<<b<<", ans "<<temp;


}