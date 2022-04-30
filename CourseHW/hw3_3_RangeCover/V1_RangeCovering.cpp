#include <iostream>
#include <list>
#include <set>
using namespace std;
//wrong ans
void rangecover(list<int> *arr, int num)
{
    int l_ptr, r_ptr;

    bool check_list[num];
    int true_counter = 1;
    set<pair<int, int>> total_order; // first: value nunber, second: list number
    list<int>::iterator itr;
    for (int i = 0; i < num; i++)
        check_list[i] = false;
    for (int i = 0; i < num; i++)
    {
        for (itr = arr[i].begin(); itr != arr[i].end(); itr++)
        {
            total_order.insert(pair<int, int>(*itr, i)); // internally sorted
        }
    }

    set<pair<int, int>>::iterator set_itr = total_order.begin(); // first: value nunber, second: list number
    l_ptr = set_itr->first;
    r_ptr = set_itr->first;
    check_list[set_itr->second] = true;
    int range_recorder[3] = {l_ptr, r_ptr,total_order.rbegin()->first-total_order.begin()->first}; //{left,right,range}
    set_itr++;
    for (; set_itr != total_order.end(); set_itr++)
    {
        // cout<<l_ptr<<" "<<r_ptr<<endl;
        // cout<<range_recorder[2]<<endl;
        if (check_list[set_itr->second] == true && true_counter < num)
        { // reset l_ptr, r_ptr, range
            // reset check_list
            
            // for (int i = 0; i < num; i++)
            //     cout<<"bool"<<check_list[i];
            // cout <<endl;
            l_ptr = set_itr->first;
            r_ptr = set_itr->first;
            for (int i = 0; i < num; i++)
                check_list[i] = false;
            check_list[set_itr->second] = true;
            true_counter = 1;
        }
        else
        {
            // if check_list not full trues: rptr move
            // if check_list full trues:
            // if cur range is smaller than check_list range,  update range_recoder with cur l_ptr, r_ptr, range,
            // else do noting and reset lptr, rptr

            if (true_counter < num)
            { // not full trues: move on
                r_ptr = set_itr->first;
                check_list[set_itr->second] = true;
                true_counter++;
            }
            else
            { // full trues: see if need to update, then reset
                if ((r_ptr - l_ptr) < range_recorder[2] )
                {
                    
                    range_recorder[0] = l_ptr;
                    range_recorder[1] = r_ptr;
                    range_recorder[2] = r_ptr - l_ptr;
                    // cout <<"range"<< (r_ptr - l_ptr) << " " << range_recorder[2]<<endl;
                    //  cout <<"range"<< range_recorder[0] << " " << range_recorder[1]<<endl;
                }
                // cout<<"reset"<<endl;
                // reset check_list
                l_ptr = set_itr->first;
                r_ptr = set_itr->first;
                for (int i = 0; i < num; i++)
                    check_list[i] = false;
                check_list[set_itr->second] = true;
                true_counter = 1;
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
    list<int> arr[m];
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