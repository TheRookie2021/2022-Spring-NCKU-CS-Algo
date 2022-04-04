    #include<iostream>
    #include<vector>
    #include<set>

    using namespace std;

    void judging(int* cocktails,int num,int num_of_judges,int kth){
        multiset<int> temp;
        for (int i = 0; i < num - num_of_judges + 1; i++){

            // sort the range: m lg(m) 
            // for (int j = 0; j < num_of_judges; j++){
            //     temp.insert(cocktails[i+j]);
            // }
            temp.insert(cocktails+i,cocktails+(i+num_of_judges));
            // output the kth small k
            if(kth<num_of_judges/2){
                multiset<int>::iterator itr=temp.begin();
                for(int j=0;j<kth-1;j++,itr++);
                cout<<*itr<<" ";

            }else{
                multiset<int>::reverse_iterator ritr = temp.rbegin();
                for (int j = 0; j < num_of_judges - kth ; j++, ritr++);
                cout<<*ritr<<" ";

            }
        }
    }

    int main(){
        ios_base::sync_with_stdio(false); // need this to reduce input output time
        cin.tie(NULL);                    // need this to reduce input output time

        int n,m,k;
        cin >> n >> m >> k;
        int cocktails[n];
        for(int i=0;i<n;i++){
            cin>>cocktails[i];
        }
        judging(cocktails,n,m,k);

        // for(int i=0;i<n;i++){
        //     cout<<cocktails[i];
        // }

        return 0;
    }