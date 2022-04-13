#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> Chapt_Content;
class Memory{
private:
    unordered_map<int,int> memory;// (chapt,content)
    // (time,Chapt_Content)-> wrong!: find(key) not find(element)
    
    int num;
    int counter;
    // time: represented as index order
public:
    Memory(int n){
        num=n;
        counter=0;
    }
        
    // - set a b，代表教授提到了章節 a 並且內容是 b，
    //     如果出現了"重複的章節"則更新其內容以及提到的時間。(更新時間與內容)
    //     (否則插入新的)  
    void set(int a, int b){
        // O(n) for finding the target
        for (int i = 0; i < memory.size(); i++)
        {

            unordered_map<int, int>::iterator itr_memo = memory.find(a);
            // update: do not change the size of memory
            if (itr_memo!=memory.end())
            {
                Chapt_Content temp = *itr_memo;
                // update content
                temp.second = b;
                // update time
                memory.erase(itr_memo);
                memory.insert(temp);
                return;
            }
        }
        // don't exist: insert
        if(counter!=num){
            memory.insert(Chapt_Content(a,b));
            counter++;
        }else{
            // flush oldest
            memory.erase(memory.begin());
            // insert new one
            memory.insert(Chapt_Content(a,b));
        }
    }
    // - get a，代表小考考到了章節 a ，你需要從你記住的內容中檢查是否存在，
    //     如果存在的話因為在腦中回憶了一遍，因此也需要"更新"提到的時間。(更新並輸出其內容)
    //     (否則輸出-1)  
    int get(int a){
        // O(lg n)
        unordered_map<int, int>::iterator itr_memo = memory.find(a);
        if (itr_memo != memory.end())
        {
            int content;
            // update: do not change the size of memory
            content = itr_memo->second;

            // update time
            Chapt_Content temp=*itr_memo;
            memory.erase(itr_memo);
            memory.insert(temp);

            // output
            return content;
        }
        return -1;
    }
};

int main(){
    // interactively output or 
    // store the instruction and output when finishing input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    Memory test(n);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        string str;
        cin>>str;
        if(str.compare("get")==0){
            cin >> x;
            cout << test.get(x)<<endl;
        }else{
            cin >> x >> y;
            test.set(x,y);
        }
    }
    return 0;
}