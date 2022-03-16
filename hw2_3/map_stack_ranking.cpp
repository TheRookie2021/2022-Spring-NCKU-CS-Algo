#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <stack>
using namespace std;
typedef pair<long long signed int, long long signed int> Pos;
class MapRank{
    private:
        map<Pos, int> sorted_pos; // key=pos, value= original pos (for indexing arr)
        vector<Pos> original_pos; // storing pos by original order
        vector<int> rk;           // store the ranking data of original
        stack<pair<Pos, int> > stk;// for shortening the time for ranking by maintain the current largest rank
                                  // premis: traverse through sorted way
        
    public:
        void print_rk(){

        };
        void ranking(){
            int x,y;
            map<Pos, int>::iterator itr = sorted_pos.begin();
            stk.push(*itr);
            itr++;
            for (; itr != sorted_pos.end(); itr++)
           {
               //new element is larger than stack top
               //push new

               //new element is smaller than stack top
               //pop until it is larger 
               //if empty, push 
           }
        };
        void inputdata(int x, int y, int index){
            sorted_pos.insert(pair<Pos,int>(Pos(x,y),index));
            original_pos.push_back(Pos(x,y));
            rk.push_back(0);

        }
}

int main()
{
    int N;
    long long signed int x, y;
    vector<Pos> rk;
    
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        rk.push_back(Pos(x, y));
        arr[i]=0;
    }
    ranking(rk,arr);

    return 0;
}