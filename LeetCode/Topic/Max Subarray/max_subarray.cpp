#include<iostream>
#include<vector>
using namespace std;

int MaxSubarr(vector<int> &num)
{
    int max=INT32_MIN;
    int ptr_right;
    ptr_right = 0;
    vector<int> order_sum(num.size(),0);
    // step1
    order_sum[0] = num[0];
    for (int i = 1; i < num.size(); i++){
        order_sum[i] = order_sum[i - 1] + num[i];
        cout<<order_sum[i]<<" ";
    }
    // step2: find max 
    for (int i = 0; i < num.size(); i++){
    cout<<max<<" ";
        if (max < order_sum[i])
            max = order_sum[i], ptr_right = i;
    }
    // step3: final
    cout<<ptr_right<<endl;
    for (int i = 0; i < ptr_right; i++){
        if (max < order_sum[ptr_right] - order_sum[i]){
            max = order_sum[ptr_right] - order_sum[i];
            cout<<"cur"<<max<<" ";
        }
    }

    return max;
}

int main(){
    int n;
    int i = 0;
    cin >> n;
    vector<int> num(n);
    while (n--)
    {
        cin >> num[i++];
    }
    cout<<MaxSubarr(num);
    return 0;
}