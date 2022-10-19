#include <iostream>
#include <string>
#include<math.h>   
using namespace std;
void fill_fibonacci_numbers(int* fib, int len) {
    fib[0] = 0; 
    fib[1] = 1; 
    int i;
    for(i = 2; i < len; i++) {
        fib[i] = fib[i-1] + fib[i-2]; 
    }
}
unsigned long long int
recur(unsigned long long int n,
      unsigned long long int x, unsigned long long int y,
       int a, int b)
{
    unsigned long long int fib[n],i;
    if (n == 1)
        return x;
    if (n == 2)
        return y;
    fib[0] = x;
    fib[1] = y;
    
    for (i = 2; i < n; i++)
    {
        fib[i] =(a* fib[i - 1] + b* fib[i - 2])%(10000007);
    
    }
    // for(unsigned long long int i=2;i<n;i++){
    //     ans=b*f1+a*f2;
    //     f1=f2;
    //     f2=ans;
    // }
    
    return fib[n-1]%(10000007);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int n, x, y, a, b;
    cin >> n >> x >> y >> a >> b;
    cout << recur(n, x, y, a, b);//%(100000000+7)
    //請輸出答案除以 10^8 + 7 之後的餘數
}   