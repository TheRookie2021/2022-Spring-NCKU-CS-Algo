#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;
//pass
void rangecover(vector<int> *arr, int num)
{
   
    vector<pair<int, int>> total_order; // first: value nunber, second: list number
    vector<int>::iterator itr;
    for (int i = 0; i < num; i++)
    {
        for (itr = arr[i].begin(); itr != arr[i].end(); itr++)
        {
            total_order.push_back(pair<int, int>(*itr, i)); 
        }
    }
    sort(total_order.begin(), total_order.end());
    int check_list[num];//count the num of group currently recorded
    int l_ptr = 0, r_ptr = 0;
    int true_counter = 0;//count the group recorded set
    int range_recorder[3] = {l_ptr, r_ptr, INT_MAX}; //{left,right,range}
    for (int i = 0; i < num; i++)
        check_list[i] = 0;
    for (; r_ptr < total_order.size(); r_ptr++)
    {
        if (check_list[total_order[r_ptr].second] == 0)
            true_counter++;
        check_list[total_order[r_ptr].second]++;

        if(true_counter==num){
            while(check_list[total_order[l_ptr].second]>1)
            {
                check_list[total_order[l_ptr].second]--;
                l_ptr++;
            }
            if (range_recorder[2] > total_order[r_ptr].first - total_order[l_ptr].first)
            {
                range_recorder[0] = total_order[l_ptr].first;
                range_recorder[1] = total_order[r_ptr].first;
                range_recorder[2] = total_order[r_ptr].first - total_order[l_ptr].first;
            }
        }
        

    }
    cout << range_recorder[0] << " " << range_recorder[1];
}

int main()
{
    int m, n;
    int temp;
    cin >> m;
    vector<int> arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    rangecover(arr, m);
    return 0;
}