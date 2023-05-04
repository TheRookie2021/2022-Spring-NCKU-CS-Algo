#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> &nums, int front, int end){
    int mid=(front+end)/2;
    if (front == end)
    {
        if (mid < nums.size() - 1)
        {
            if (nums[mid] > nums[mid + 1])
            {
                return  mid+1;
            }
        }
        return 0;
    }
    int l,r;
    l = findPivot(nums, front, mid);
    r = findPivot(nums, mid + 1, end);
    if (r != 0)
        return r;
    return l;
}
// from rotated to ascending order
int pivotConvertRtoV(int index, int pivot, int len){
    //pivot=4
    // 0 1 2 3 |4 5 6
    // 4 5 6 7 |0 1 2

    // 0 1 2 |3 4 5 6
    // 0 1 2 |4 5 6 7
    if(index>=len) return index;
    if(index<0) return index;
    return index >= pivot ? (index -  pivot) : (index + (len-pivot));
}

// from  ascending to rotated order
int pivotConvertVtoR(int index, int pivot, int len){
    //pivot=4
    // 0 1 2 |3 4 5 6
    // 0 1 2 |4 5 6 7

    // 0 1 2 3 |4 5 6
    // 4 5 6 7 |0 1 2
    if(index>=len) return index;
    if(index<0) return index;
    return index >= (len-pivot) ? (index - (len-pivot)) : (index + pivot);
}


int binarySearch(vector<int> &nums, int target){
    // R: rotated array/real
    // V: virtural
    // input: R 
    // binary search: A
    // output: index of R
    if(nums.size()==1){
        if(nums[0]==target)return 0;
        else return -1;
    }

    int pivot = findPivot(nums, 0, nums.size() - 1);
    
    // represent real memory space
    int left = pivotConvertVtoR(0, pivot, nums.size()) ;// to see where the smallest element is in rotated array
    int right = pivotConvertVtoR(nums.size()-1, pivot, nums.size());
    
    // debug
    // int i =0;
    //     cout <<"Real \t" <<left << " " << right << endl;
    //     cout <<"virtual \t"<< pivotConvertRtoV(left, pivot, nums.size()) << " " << pivotConvertRtoV(right, pivot, nums.size())<<endl;

    // virtual binary search
    while (pivotConvertRtoV(left, pivot, nums.size()) <= pivotConvertRtoV(right, pivot, nums.size())) // bug: must be <=, think about the case with one element
    {
        int virtual_mid = (pivotConvertRtoV(left, pivot, nums.size()) + pivotConvertRtoV(right, pivot, nums.size())) / 2;
        
        // debug
        // i++;
        // cout << "Real \t" << left << " " <<  pivotConvertVtoR(virtual_mid, pivot, nums.size())<< " " << right << endl;
        // cout << "Virtual \t" << pivotConvertRtoV(left, pivot, nums.size()) << " " << virtual_mid<< " " << pivotConvertRtoV(right, pivot, nums.size()) << endl;

        if (target < nums[pivotConvertVtoR(virtual_mid, pivot, nums.size())])
        {
            right = pivotConvertVtoR(virtual_mid - 1, pivot, nums.size());
        }
        else if (nums[pivotConvertVtoR(virtual_mid, pivot, nums.size())] < target)
        {
            left = pivotConvertVtoR(virtual_mid + 1, pivot, nums.size());
        }
        else
        {
            return pivotConvertVtoR(virtual_mid, pivot, nums.size());
        }
    }
    return -1;
}


int main(){
    
    vector<int> nums={4,5,6,7,0,1,2};
    int target = 0;
    
    // vector<int> nums={1};
    // int target = 0;
    
    // vector<int> nums={1,3};
    // int target = 1;
    
    // vector<int> nums={3,1};
    // int target = 1;
    // vector<int> nums={1,3};
    // int target = 4;
    cout<< "pivot "<<findPivot(nums,0,nums.size()-1);
    cout <<"\nans " <<binarySearch(nums, target);
    
    
    // cout<<endl;
    // for(int i =0;i<nums.size();i++)
    //     cout << i<<" ";
    // cout<<endl;
    // for(int i =0;i<nums.size();i++)
    //     cout << nums[i]<<" ";
    // cout<<endl;
    // cout<<endl;
    // for(int i =0;i<nums.size();i++){
    //     cout << pivotConvertVtoR(i, findPivot(nums, 0, nums.size() - 1), nums.size())<<" ";
    // }
    // cout<<endl;
    // for(int i =0;i<nums.size();i++){
    //     cout << nums[pivotConvertVtoR(i, findPivot(nums, 0, nums.size() - 1), nums.size())]<<" ";
    // }
    
    return 0;
}