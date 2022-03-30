#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;
typedef pair<double,string> Concen_Name;

void swap(Concen_Name *a,Concen_Name*b){
    Concen_Name temp=*a;
    *a=*b;
    *b=temp;
}
int partition(vector<Concen_Name> *vec, int start, int end)
{
    Concen_Name pivot = vec->at(end);
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (vec->at(j).first < pivot.first)
        {
            i++;
            swap(&vec->at(i), &vec->at(j));
        }
    }
    swap(&vec->at(i + 1), &vec->at(end));
    return i + 1;
}
// double find_max(double a,double b)
// {
//     return (a > b) ? a : b;
// }
// double find_min(double a, double b)
// {
//     return (a > b) ? b : a;
// }
// double medien_of_three(double a,double b,double c)
// {
//     int max = find_max(find_max(a, b), c);
//     int min = find_min(find_min(a, b), c);
//     int total = a + b + c;
//     return total - min - max;
// }
int rand_partition( vector<Concen_Name>* vec,int start,int end){
    srand(time(NULL));
    if((start-end+1)==0)return partition(vec,start,end);//RTE bug! be ware of divid with zero 

    int i=start+(rand()%(start-end+1));
    // int i=start;
    swap(&vec->at(i), &vec->at(end));
    return partition(vec,start,end);
}
string quick_select( vector<Concen_Name>* vec,int target,int start,int end)
{
    if(start==end){
       return vec->at(start).second;
    }
    int mid=rand_partition(vec,start,end);
    int k=mid-start+1;
    if(target==k){
        return vec->at(mid).second;
    }else if(target<k){
        return quick_select(vec,target,start,mid-1);
    }else{

        return quick_select(vec,target-k,mid+1,end);
    }
}
int main(){
    int n,kth;
    string tempstr;
    cin >> n >> kth;
    vector<Concen_Name> vec(n);
    double ta,tb,tc;
    for (int i = 0; i < n; i++)
    {
        cin >> ta >> tb >> tc >> tempstr;
        vec[i].first = tc / (ta + tb + tc);
        vec[i].second = tempstr;
    }
    cout << quick_select(&vec, n-kth+1, 0, n - 1);
    // for(auto i:vec){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    return 0;
}