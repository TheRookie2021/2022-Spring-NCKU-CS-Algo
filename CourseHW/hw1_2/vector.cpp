#include <vector>
#include <iostream>
using namespace std;
//Vectors can be thought of as arrays that can grow (and shrink) in length while your program is running.
//Vectors are formed from a template class in the Standard Template Library (STL).


int main()
{
    //declaration:
    //declaring a vector variable, template class 
    vector<int> v;

    //vector constructor:
    //vector<AClass> record(20);// default constructor for AClass to initialize 20 elements.

    //v[i]: change existed element
    //You can use v[i] to change the value of the i th element. 
    //However, you cannot initialize the i th element using v[i]

    //push_back(type): add new element
    vector<double> sample;
    sample.push_back(0.0);
    sample.push_back(1.1);
    sample.push_back(2.2);
    //size:
    //The function size returns a value of type unsigned int , not a value of type int
    
    cout<<"sample"<<endl;
    for(int i=0;i<sample.size();i++)
        cout<<sample[i]<<endl;
 
    //resize and reserve
    //.reserve to explicitly increase the capacity of a vector.
    //.resize change the size of a vector
    v.resize(10);
    cout<<"v"<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
        
    for(int i=0;i<v.size();i++)
    {
        v[i]=i;
        cout<<v[i]<<endl;
    }

    return 0;
}