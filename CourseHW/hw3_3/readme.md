#  10 . Smallest Range Covering Elements from k Lists
給定 k 個 lists ，每個 list 都已經為非遞減排列。
你的工作就是找出一個能至少能包含每個 list 其中一個數字並且為最小的範圍。
我們定義範圍 [a,b] 小於 [c,d] 為 b - a < d - c 或 a < c if b - a == d - c

 Smallest Range Covering Elements from k Lists: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

 heap: https://leetcode.com/tag/heap-priority-queue/

problem:
    a b c  a  b  c a b c
    0 3 10 11 12 18...
    1st. a~c: 10-0
    2nd. b~c: 11-3
    but in current algorithm, the second one would be skipped
    idea for sol.: see string search method in DS 
# ans
'''
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int mx=INT_MIN;
        int cans=INT_MAX;
        int lo=INT_MIN,hi=INT_MAX;
        for(unsigned int i=0;i<nums.size();i++)
        {
            mx=max(mx,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int na=mx-x.first+1;
            if(cans>na)
            {
                cans=na;
                lo=x.first;
                hi=mx;
            }
            if(x.second.second>=nums[x.second.first].size()-1)
                break;
            pq.push({nums[x.second.first][x.second.second+1],{x.second.first,x.second.second+1}});
            mx=max(mx,nums[x.second.first][x.second.second+1]);
        }
        return {lo,hi};
    }
    
int main () {
    int n, k, a;
    cin >> n;
    std::vector<vector<int>> wholevector;
    for (int i=0;i<n;i++) {
                cin >> k;
                vector<int> tmpvector;
                for (int j=0;j<k;j++) {
                        cin >> a;
                        tmpvector.push_back(a);
                }
                wholevector.push_back(tmpvector);
        }

        vector<int> result =  smallestRange(wholevector);
        for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
'''