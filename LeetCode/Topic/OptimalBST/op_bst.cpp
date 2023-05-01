#include <iostream>
using namespace std;

int recurT(int l, int r)
{
    if (l >= r)
        return 1;

    int total = 0;
    int left_sub=0,right_sub=0;
    for (int mid = l; mid <= r; mid++)
    {
        left_sub= recurT(l, mid - 1);
        right_sub= recurT(mid + 1, r);
        total+=left_sub*right_sub;
    }
    return total;
}
int numTrees(int n)
{
    // catalan's num
    return recurT(1, n);

}
int main()
{
    int n;
    cin >>n;
    cout<<numTrees(n);
    return 0;
}