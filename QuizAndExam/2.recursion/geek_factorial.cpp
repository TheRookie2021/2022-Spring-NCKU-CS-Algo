// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 

vector<int> sumLarge(vector<int> a, vector<int> b)
{
    vector<int> sum;
    if (a.size() < b.size())
    {
        vector<int> temp = a;
        a = b;
        b = temp;
    }
    int carry=0;
    for (int i = 0; i < b.size(); i++)
    {
        int result = a[i] + b[i] + carry;
        if (result > 9)
            carry=1;
        else
            carry = 0;
        
        sum.push_back(result%10);
    }
    for (int i = b.size(); i < a.size(); i++)
    {
        int result = a[i] + carry;
        if (result > 9)
            carry=1;
        else
            carry = 0;
        sum.push_back(result%10);
    }
    if(carry)sum.push_back(carry);
    return sum;
}
// MUltiply the number x with the number
// represented by res array
vector<int> multiply(unsigned long long int n, vector<int> digits)
{
    // Initialize carry
    unsigned long long int carry = 0;
 
    // One by one multiply n with
    // individual digits of res[]
    for (unsigned long long int i = 0; i < digits.size(); i++) {
        unsigned long long int result
          = digits[i] * n + carry;
 
        // Store last digit of 'prod' in res[]
        digits[i] = result % 10;
 
        // Put rest in carry
        carry = result / 10;
    }
 
    // Put carry in res and increase result size
    while (carry) {
        digits.push_back(carry % 10);
        carry = carry / 10;
    }
 
    return digits;
}
 
// Function to recursively calculate the
// factorial of a large number
vector<int> recur(unsigned long long int n,
                  unsigned long long int x, unsigned long long int y,
                  int a, int b)
{
    if (n < 1)
        return {0};
    if (n == 1)
        return multiply(x, {1});
    if (n == 2)
        return multiply(y, {1});
    return sumLarge(multiply(a, recur(n - 1, x, y, a, b)),
               multiply(b, recur(n - 2, x, y, a, b)));
}

 
int main()
{
    unsigned long long int n, x, y, a, b;
    cin >> n >> x >> y >> a >> b;
    vector<int> ans= recur(n, x, y, a, b);//%(100000000+7)
    for(int i=ans.size()-1;i>-1;i--){
        cout<<ans[i];
    }
    //請輸出答案除以 10^8 + 7 之後的餘數
}   