#include <iostream>
#include <climits>
using namespace std;

void dp(int arr[], int n)
{
    int memo[n + 1];
    int max_sum;

    for (int i = 0; i <= n; i++)
    {
        memo[i] = 0;
    }

    //  5
    //   6 -1 5 4 -7
    //  sum of i~j
    //        j=0, 1, 2, 3, 4
    //   i=0   6  5  10  14 7
    //   i=1  X   -1 4   8  -1
    //   i=2
    //   i=3

    // rule:
    //  memo[i][j]= arr[i-1]+memo[i][j-1]
    //  skip i>j
    int max = INT_MIN, op = 0, ed = 0;
    for (int i = 1; i <= n; i++)
    {
        memo[i - 1] = 0;
        for (int j = i; j <= n; j++)
        {
            memo[j] = arr[j - 1] + memo[j - 1];
            cout << memo[j] << " ";
            if (max < memo[j])
            {
                max = memo[j];
                op = i;
                ed = j;
            }
        }
        cout << endl;
    }
    cout << max << " " << op << " " << ed;
}

void dp2(int arr[], int n)
{
    int memo[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = 0;
    }

    int max_sum = INT_MIN, min_sum = INT_MAX, min_i = 0, op = 1, ed = 0;
    for (int j = 1; j <= n; j++)
    {
        memo[j] = arr[j - 1] + memo[j - 1];
        // cout << memo[j] << " ";
        if (max_sum < memo[j])
        {
            max_sum = memo[j];
            ed = j;
        }
    }
   
    for (int j = 1; j <= n; j++)
        if (min_sum > memo[j])
        {
            min_sum = memo[j];
            min_i = j ;
        }
    //---------------------
    // min sum is in front of max sum
    if (min_i < ed)
    {
        if (min_sum < 0)
        {
            max_sum -= min_sum;
            op = min_i+1;
        }
    }
    else{
        // min sum is "not" in front of max sum
        int temp=INT_MAX,temp_i;
        for (int j = 1; j <= ed; j++)
            if (temp > memo[j])
            {
                temp = memo[j];
                temp_i = j + 1;
            }
        temp = max_sum - temp;

        if (min_sum < 0)
        {
            for (int j = min_i+1 ; j <= n; j++)
            {
                if (max_sum < (memo[j] - min_sum) ){
                    max_sum = memo[j] - min_sum;
                    op = min_i + 1;
                    ed=j;
                }
            }
        }
        max_sum = (temp > max_sum) ? temp : max_sum;
        op = (temp == max_sum) ? temp_i : min_i + 1;
    }

    cout << max_sum << " " << op << " " << ed;
}

void dp3(int arr[], int n)
{
    if(n==1){
        cout << arr[0] << " " << 1 << " " << 1;
    }
    // find max and min in memo
    // case 1: min max; return (max-min)
    // case 2: max min; find max behind cur max with min, return the larger one  
    int memo[n + 1];
    int max_sum;

    for (int i = 0; i <= n; i++)
    {
        memo[i] = 0;
    }

    //  5
    //   6 -1 5 4 -7
    //  sum of i~j
    //        j=0, 1, 2, 3, 4
    //   i=0   6  5  10  14 7
    //   i=1  X   -1 4   8  -1
    //   i=2
    //   i=3

    // rule:
    //  memo[i][j]= arr[i-1]+memo[i][j-1]
    //  skip i>j
    int max = INT_MIN,min=INT_MAX, min_i,op = 1, ed = 0;
    for (int j = 1; j <= n; j++)
    {
        memo[j] = arr[j - 1] + memo[j - 1];
        // cout << memo[j] << " ";
        if (max < memo[j])
        {
            max = memo[j];
            ed = j;
        }
        if (min > memo[j])
        {
            min = memo[j];
            min_i = j;
        }
    }
    // cout<<"min"<<min<<" "<<min_i<<endl;
    if(min<0){
        if(min_i<ed){
            //case 1: min max
            // cout<<"c1"<<endl;
            if(max<max-min){
                max=max-min;
                op=min_i+1;
            }
        }else{
            //case 2:
            if(min-max>max){
                int temp=op;
                op=ed+1;
                ed=op;
                max=min-max;
            }
            // cout<<"c2"<<endl;
            if(min_i!=n){
                for (int i = min_i + 1; i <= n; i++)
                {
                    // cout << max + " ";
                    if (max < memo[i] - min)
                    {
                        max = memo[i] - min;
                        ed = i;
                        op = min_i+1;
                    }
                }
            }
            else
            {   //min_i=n
                min=INT_MAX;
                //find new min before max
                for (int j = 1; j <= ed; j++)
                    if (min > memo[j])
                    {
                        min = memo[j];
                        min_i = j;
                    }
                if (min < 0 && min_i!=ed)
                {
                   if(max<max-min){
                       max = max - min;
                       op = min_i + 1;
                   }
                }
            }
        }

    }
    max_sum=max;
    cout << max_sum << " " << op << " " << ed;
}

void dp4(int arr[], int n)
{
    if(n==1){
        cout << arr[0] << " " << 1 << " " << 1;
    }
    
    int memo[n + 1];
    int max_sum;

    for (int i = 0; i <= n; i++)
    {
        memo[i] = 0;
    }

   int max = INT_MIN,min=INT_MAX, min_i,op = 1, ed = 0;
    for (int j = 1; j <= n; j++)
    {
        memo[j] = arr[j - 1] + memo[j - 1];
        // cout << memo[j] << " ";
        if (max <= memo[j])
        {
            max = memo[j];
            ed = j;
        }
        if (min >= memo[j])
        {
            min = memo[j];
            min_i = j;
        }
    }
   if(min_i<ed){
       // case 1: min max
       //  cout<<"c1"<<endl;
       if (max < max - min)
       {
           max = max - min;
           op = min_i + 1;
       }
       else
       {
           op = 1;
       }
   }
   else
   {
       //1~maxi
       for(int i=1;i<ed;i++){
           if(max-memo[i]>max){
               max=max-memo[i];
               ed=ed;
               op=i+1;
           cout<<"a";
           }
       }

       //maxi~mini

       for(int i=ed;i<min_i;i++){
           if(memo[i]-max>max){
                max=min-memo[i];
                ed=min_i;       
                op=i+1;
        cout<<"b"<<i;
           }
       }
       //mini~n
       for(int i=min_i+1;i<=n;i++){

           if(memo[i]-min>max){
               max=memo[i]-min;
               ed=i;
               op=min_i+1;
           cout<<"c";
           }
       }
   }
    max_sum=max;
    cout << max_sum << " " << op << " " << ed;



}
// ans
int maxSubArray(int arr[], int n){
    int i = 1, tot = 0, max = INT_MIN, pre_op = 1, op = 1, ed = 1;
    for (; i <= n; i++)
    {
        tot += arr[i-1];
        if (max < tot){
            max = tot, ed = i;
            pre_op=op;
        }
        if (tot < 0)
            tot = 0,op=i+1;
  }
  cout << max << " " << pre_op << " " << ed;
  return max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // dp(arr, n);
    // cout << endl;  
    // cout << endl;  
    maxSubArray(arr, n);
    return 0;
}