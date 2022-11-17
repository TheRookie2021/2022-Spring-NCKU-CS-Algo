#include<iostream>
using namespace std;

int main(){
    int x=3;
    int temp=0;
    int arr[3][3][3];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            for (int k = 0; k < x; k++)
                arr[i][j][k] = temp++;

    for (int i = 0; i < x; i++){
cout<<"i="<<i<<endl;
        for (int j = 0; j < x; j++){
            cout<<"j="<<j<<endl;
            for (int k = 0; k < x; k++)
                cout << arr[i][j][k]<<"\t";
        cout<<endl;
        }
    }
    cout<<endl;
    for (int i = 0; i < x; i++)
    {
        cout << "i=" << i << endl;
        for (int j = 0; j < x; j++)
        {
            cout << "j=" << j << endl;
            for (int k = 0; k < x; k++)
            {
                temp = (int64_t)&arr[i][j][k];
                cout << temp % 1000 + 1000 << "\t";
            }
            cout << endl;
        }
    }
}
