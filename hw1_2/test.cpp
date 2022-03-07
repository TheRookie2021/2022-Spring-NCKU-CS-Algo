#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack< set<string> > s;
    set<string> n,m, temp;
    n.insert("{}");
    s.push(n);
    
    n.insert("{{}}");
    s.push(n);
    
    temp=s.top();
    s.pop();
    cout<<*temp.begin()<<endl;
    
    temp=s.top();
    s.pop();
    cout<<*temp.begin()<<endl;
    return 0;
}