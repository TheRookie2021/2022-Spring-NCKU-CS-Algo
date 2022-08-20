#include<iostream>
using namespace std;

void insertionSort(int *arr,int n){
    int key;
    for(int i =1;i<n;i++){
        key=arr[i];
        for(int j=i-1; j>-1;j--){
            
            if(key<arr[j]){
                arr[j+1]=arr[j];
                if(j==0){
                    arr[j] = key;
                    break;
                }
            }else{
                arr[j + 1] = key;
                break;
            }
        }
    }

}

int main(){
    int arr[10];
    for(int i =0;i<10;i++){
        cin>> arr[i];
    }

    insertionSort(arr,10);

    for(int i =0;i<10;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}