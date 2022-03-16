#include<iostream>

using namespace std;
void recur_comb(int *arr,int *data, int start,int num, int counter, int max)
{
    //end condition
    if (counter == max)
    {
        for (int i = 0; i < max; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < num; i++)
    {
        data[counter] = arr[i];
        
        //bug fixed: i+1 instead of start+1
        recur_comb(arr, data, i + 1, num, counter + 1, max);
    }

    //those who are not hit counter==max and counter is less than max are ignored
}

//connect with the entrance of recurrsive function
void print_comb(int *arr, int num, int max)
{
    // use another function to creat/store temp arr
    // because we do not need the data to do sth more, we only want to print it out
    int data[max];
    recur_comb(arr, data, 0, num, 0, max);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int temp;
    cin>>N;
    int lots[N];
    for(int i=0;i<N;i++){
        cin>> temp;
        lots[i] = temp;
    }

    print_comb(lots,N,6);
    return 0;
}