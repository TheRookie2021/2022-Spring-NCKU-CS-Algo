/*min-heapify*/
#include<iostream>
using namespace std;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify_iterative (int arr[], int n){
    int top=n-1;
    for(int i=top/2;i>-1;i--){
        // bottom up exam: start from top/2
        int l = i * 2 + 1, r = i * 2 + 2;
        int min_i;
        if(l<=top && arr[l]<arr[i]){
            min_i=l;
        }else
            min_i=i;

        if(r<=top && arr[r]<arr[min_i]){
            min_i=r;
        }
        if(min_i!=i){
            // top down exchange
            swap(&arr[i],&arr[min_i]);
            for(int j=min_i;j<top;){
                int jl = 2 * j + 1, jr = 2 * j + 2;
                int j_min;
                if(jl<=top&&arr[jl]<arr[j]){
                    j_min = jl;
                }else{
                    j_min = j;
                }
                if(jr<=top&&arr[jr]<arr[j_min]){
                    j_min = jr;
                }
                if(j_min!=j){
                    swap(&arr[j],&arr[j_min]);
                    j=j_min;
                }else{
                    break;
                }
            }
        }
    }
}
int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    heapify_iterative(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}