#include <iostream>
#include <random>
using namespace std;

int main(){
    int n,m,temp;
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    for(int i=0;i<m;i++)
    {
        temp=gen()%4;
        switch (temp)
        {
        case 0:
            cout << "move " << (gen() % n) + 1 << " onto " << (gen() % n) + 1 << endl;
            break;
        case 1:
            cout << "move " << (gen() % n) + 1 << " over " << (gen() % n) + 1 << endl;
            break;
        case 2:
            cout << "pile " << (gen() % n) + 1 << " onto " << (gen() % n) + 1 << endl;
            break;
        case 3:
            cout << "pile " << (gen() % n) + 1 << " over " << (gen() % n) + 1 << endl;
            break;
        }
    }
    return 0;
}