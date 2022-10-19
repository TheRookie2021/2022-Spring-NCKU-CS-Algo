#include <iostream>
using namespace std;
#define MAX 500

unsigned long long int f[92][MAX];


// Maximum number of digits in output
 
int multiply(int x, int res[], int res_size);
 
// This function finds factorial of large numbers
// and prints them
int* factorial(int n)
{
    int res[MAX];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
 
       return res;
}
 

int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10; 
 
        // Put rest in carry
        carry  = prod/10;   
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
 

int* longDivision(int* number, int divisor)
{
    // As result can be very large store it in string
    int* ans;
    int size=sizeof(number)/sizeof(number[0]);
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (size > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans == 0)
        return 0;
 
    // else return ans
    return ans;
}
 
int main()
{
    int n;
    cin >> n;
    int h, total, M_v = n / 2;
    unsigned long long int  counter = 1;
    for (int i = 1; i <= M_v; i++)
    {
        h = n -( 2 * i);
        total = h + i;
        int *ft=factorial(total);
        int *fh=factorial(h);
        int *fi=factorial(i);
       unsigned long long int ans = longDivision(ft, multiplies(fh * fi);

       counter += ans;
    }

    cout << counter;

    return 0;
}