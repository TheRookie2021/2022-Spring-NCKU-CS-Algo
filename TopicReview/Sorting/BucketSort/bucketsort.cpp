#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_bucket(vector<vector<double>> bucket){
    for (int i = 0; i < bucket.size(); i++)
    {
        cout<<"B["<<i<<"]: ";
        for (int j = 0; j < bucket[i].size(); j++){
            cout<<bucket[i][j]<<" ";
        }
        cout << endl;
    }
}


void bucket_sort(vector<double> vec){
    vector<vector<double>> bucket(vec.size());
    for (int i = 0; i < vec.size(); i++)
    {
        bucket[(int)(vec[i] * vec.size())].push_back(vec[i]);
    }
    print_bucket(bucket);
    for (int i = 0; i < bucket.size(); i++)    
        sort(bucket[i].begin(),bucket[i].end());
    cout<<endl;
    print_bucket(bucket);
    int counter=0;
    for (int i = 0; i < bucket.size(); i++)
    {
        for (int j = 0; j < bucket[i].size(); j++){
            vec[counter++] = bucket[i][j];
        }
    }
    
    for (int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
}


int main()
{
    double x,temp;
    cin >> x;
    vector<double> vec;
    for (int i = 0; i < x; i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }

    bucket_sort(vec);
    cout<<endl<<" "<< 0.001 <<" "<<(int)0.001<<" "<<0.9<<" "<<(int)0.9;
    return 0;
}