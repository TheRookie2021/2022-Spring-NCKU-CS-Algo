

# think about the possibility of all cases with test data
6
-1 5 -2 30 -1 -100 24

how to split? 
sol: find the smallest interval  
-1 5 -3 30 -1 -1 24
32+24
5+52
  
-1 5 -2 30 -1 -1 24
33+24
5+52
  
10
18 8 -48 36 -12 41 -16 -38 -20 1 
ans:
41+36-12+26=91

what about? 
sol: negative interval  
-2 1 2 3 5 -10
FIRST BETTER IDEA
    // if we use msa for finding the first bigest seq, to find the sec max seq:
    // case 1: it contains in the first seq ->possible; sol: find the smallest negtive interval to split the two seq
    // case 2: it is outside of the first seq ->possible; sol: search outside of the range
    // it is overlaping with the first seq ->possible? intuitionally, nop.

WHAT ABOUT:
change the first step of the problem into:
find the min negative continuous subseq.
1. find that.  
2. split the array if possible(if not, return the sum of the whole array)  
    2.1 there may be one subseq left( if the MNS is start from 1 or n)  
    2.2 there may be twe subseq left( else                           )  
3.1 if 2.1, recursively split? nop, at most twice 
3.2 if 2.2, find the largest seq respectively

e.g
2 -1 7 -8 7 -1 2


#
''' c

// int maxSubArray(int arr[], int n)
// {
//     int i = 1, tot = 0, max = INT_MIN, sec_max = INT_MIN, pre_op = 1, op = 1, ed = 1;
//     // searching for the non overlaping max subset
//     for (; i <= n; i++)
//     {
//         tot += arr[i - 1];
//         if (max < tot)
//         {
//             max = tot;
//             ed = i;
//             pre_op = op;
//         }
//         if (tot <= 0)
//             tot = 0, op = i + 1;
//     }

//     tot = 0;
//     for (i = 1; i < pre_op; i++)
//     {
//            tot += arr[i - 1];
//             if (sec_max < tot)
//             {
//                 sec_max = tot;
//             }
//             if (tot < 0)
//                 tot = 0;
//     }
    
//     cout << pre_op<< " " << ed << " " << endl;
//     tot = 0;
//     for (i = ed + 1; i <= n; i++)
//     {
//         tot += arr[i - 1];
//         if (sec_max < tot)
//         {
//             sec_max = tot;
//         }
//         if (tot < 0)
//             tot = 0;
//     }
    
//     if (sec_max == INT_MIN)
//         sec_max = 0;
//     cout << max << " " << sec_max << " " << endl;
//     cout << max + sec_max;
//     return max + sec_max;
//     // if we use msa for finding the first bigest seq, to find the sec max seq:
//     // case 1: it contains in the first seq ->possible; sol: find the smallest negtive interval to split the two seq
//     // case 2: it is outside of the first seq ->possible; sol: search outside of the range
//     // it is overlaping with the first seq ->possible? intuitionally, nop.
// }

// int maxSubArray2(int arr[], int n)
// {
//     if(n==1){
//         cout << arr[0];
//         return arr[0];
//     }
//     int  tot = 0, min = INT_MAX, op = 1, temp_op = 1, ed = 1;
//     int max_sum = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         tot += arr[i - 1],max_sum+= arr[i - 1];
//         if (min > tot)
//         {
//             min= tot;
//             ed = i;
//             op = temp_op;
//         }
//         if (tot >= 0)
//             tot = 0, temp_op = i + 1;
//     }

//             cout<<op<<" "<<ed<<endl;
//     // if min>=0, just return the sum of the entire array
//     if (min < 0)
//     {
//         max_sum=0;
//         if (op == 1 && ed == n)
//         {//case1. all negative
//             // find the two max
//             int max_st = INT_MIN, max_nd = INT_MIN, flag;
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
//             max_sum=max_st+max_nd;
//         }
//         else if (op == 1)
//         {// case2. start at begining
//             // split again
//             op = 2, temp_op = 2, ed = 2;
//             for (int i = 2; i <= n; i++)
//             {
//                 tot += arr[i - 1];
//                 if (min > tot)
//                 {
//                     min = tot;
//                     ed = i;
//                     op = temp_op;
//                 }
//                 if (tot >= 0)
//                     tot = 0, temp_op = i + 1;
//             }
//         }
//         else if (ed == n)
//         {//case3. end at end
//             // split again
//             op = 1, temp_op = 1, ed = 1;
//             for (int i = 1; i <= n-1; i++)
//             {
//                 tot += arr[i - 1];
//                 if (min > tot)
//                 {
//                     min = tot;
//                     ed = i;
//                     op = temp_op;
//                 }
//                 if (tot >= 0)
//                     tot = 0, temp_op = i + 1;
//             }
//         }

//         // find max seq on each side
//         if(max_sum==0){
//             // left side
//             cout<<op<<" "<<ed<<endl;
//             int max_st = INT_MIN;
//             tot=0;
//             for (int i = 1; i <= op - 1; i++)
//             {
//                 tot += arr[i - 1];
//                 if (max_st < tot)
//                 {
//                     max_st = tot;
//                 }
//                 if (tot < 0)
//                     tot = 0;
//             }
//             // right side
//             int  max_nd = INT_MIN;
//             tot=0;
//             for (int i = ed + 1; i <= n; i++)
//             {
                
//                 tot += arr[i - 1];
//                 if (max_nd < tot)
//                 {
//                     max_nd = tot;
//                 }
//                 if (tot < 0)
//                     tot = 0;
//             }
            
//             cout<<max_st<<" "<<max_nd<<endl;
//              max_sum=max_st+max_nd;
//         }
    
//     }

//     cout << max_sum;
//     return max_sum;
// }

'''