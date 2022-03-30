#include <iostream>
#include <algorithm>
using namespace std;

void conquer(long int *arr, long int front, long int mid, long int back, unsigned long int *counter)
{
    if(front==back)return;
    int ptr = front;
    int len = mid - front + 1;

    //start from back half
    for (int i = mid + 1; i < back + 1; i++)
    {
        if (len == 0)
                break;
        // ptr point to the smallest in the front half
        while(1){
            if (len == 0)
                break;

            // front value > back value: counter +len
            if (arr[ptr] > arr[i])
            {
                (*counter) += len;
                break;
            }
            // front value < back value: len--, ptr++
            else
            {
                ptr++;
                len--;
            }
        }
    }
    //sort
    sort(&arr[front], &arr[back+1]);
}
void divid(long int *arr, long int front, long int back, unsigned long int *counter)
{
    if (front == back)
        return;

    divid(arr,front,(front+back)/2,counter);
    divid(arr,1+(front+back)/2,back,counter);
    conquer(arr,front,(front+back)/2,back,counter);
}


int main()
{
    unsigned long int N;
    long int temp;
    unsigned long int counter = 0;
    cin >> N;
    long int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    divid(arr,0,N-1,&counter);
    cout << counter % 524287  ;

    return 0;
}