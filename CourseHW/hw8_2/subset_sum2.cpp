#include <iostream>
#include <climits>
using namespace std;
int max_f(int a, int b)
{
    return (a > b) ? a : b;
}
void print_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int subarr_sum(int sum[],int op,int ed){
    // op and ed : 1~n    
    return sum[ed]-sum[op-1];
}
// void maxSubArray4(int arr[], int n)
// {
//     bool goon=false;
//     int num_of_pos=0,sum[n + 1], max_subseq[n + 1+1];
//     sum[0] = 0;
//     max_subseq[0] = 0;
//     max_subseq[n + 1] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         if(arr[i-1]>=0)num_of_pos++;
//         sum[i]=sum[i-1]+arr[i-1];
//         if(arr[i-1]>=0)goon=true;
//     }
//     if(num_of_pos==1)goon=false;
//     if(!goon ){
//         // all negative
//          int max_st = INT_MIN, max_nd = INT_MIN, flag;
//             for(int i=1;i<=n;i++){
//                 if(arr[i-1]>=max_st){
//                     max_st=arr[i-1];
//                     flag=i;
//                 }
//             }
//             for(int i=1;i<=n;i++){
//                 if(arr[i-1]>=max_nd&&i!=flag){
//                     max_nd=arr[i-1];
//                 }
//             }
        
//         cout<<max_st+max_nd;
//         return;
//     }
    
    

//     //---------------------------------------------------------
//     int  tot = 0;
//     // searching for the non overlaping max subset
//     for (int i = 1; i <= n; i++)
//     {
//         tot += arr[i - 1];
      
//         if (tot <= 0)
//              tot = 0;
//         max_subseq[i]=tot;        
//     }

//     //--------------------------------------------------------- 
//     // record the largest sum in each interval(between 0)
//     int max=INT_MIN,flag=INT_MIN,flag_i, max_arr[n],counter=0;
//     for (int i = 1; i <= n; i++)
//     {   
//         if(max<max_subseq[i])
//             max=max_subseq[i];
//         if(max_subseq[i]<=0||i==n){

//             max_arr[counter++]=max;
            
//             if (flag < max)//record where the largest subseq sum is 
//                 flag = max,flag_i=counter-1;
//             max = INT_MIN;
//         }
//     }

    
   
//     int max_sum=flag, sec_max=INT_MIN;
//     for(int i =0;i<counter;i++){
//         if(flag_i!=i){
//             if(sec_max<max_arr[i])
//                 sec_max=max_arr[i];
//         }
//     }
//     if(sec_max!=INT_MIN)
//         max_sum += sec_max;
//     // for(int i =0;i<counter;i++){
//     //     // cout<<max_sum<<" "<<flag+max_arr[i]<<endl;
//     //     if(flag_i!=i)
//     //         max_sum=max_f(max_sum,flag+max_arr[i]);
//     // }
//     print_arr(sum, n + 1);
//     print_arr(max_subseq, n + 1);
//     print_arr(max_arr, counter);
//     cout<<max_sum;
// }
void dp(int arr[],int n){
    int memo[n+1][n+1];
    for(int i =0;i<=n;i++)
        for(int j =0;j<=n;j++)
            memo[i][j] = 0;

    // O(n^2): all possible
    //      n: 0 1 2 3 4 5
    // i=0     0 -7 21....
    // i=1   
    // i=2

    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++)
        {

        }
    }
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
    // cout<<"\t";
    // print_arr(arr,n);
    dp(arr, n);
    return 0;
}