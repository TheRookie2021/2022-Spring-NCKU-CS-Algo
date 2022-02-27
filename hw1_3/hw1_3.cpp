#include <iostream>
#include <string>
using namespace std;
struct Chapter{
    int chapt;
    int content;
    struct Chapter * forwardlink;
    struct Chapter * backwardlink;
};

class test{
    private:
        int num;//total memory
        int memory_used;//current used memory
        struct Chapter* head;
        struct Chapter* btm;
        
    public:
        test(int n){
            num=n;
            memory_used=0;
            head=NULL;
            btm=NULL;
        }

        //if full, 
        bool isFull(){

        }
        //tool for flush
        //delete the first content
        void deleteFront(){

        }

        //check for existent of chapt in memory
        //if exist, return the node ptr
        //else return null
        struct Chapter* search(int chapt){

        }

        //if chpater existed
        //update the content of existing chapter
        //put the updated node to the top
        void update(int chapt){

        }

        //if not full, and chapter not exist
        //insert new node
        void insert(int chapt, int content){

        }

        //if full, and chapter not exist
        //delete the oldest node and insert new node
        void flush(int chapt, int content){

        }
        //user interface function (1)
        //means that professor teaches chapter  and the content of it is . 
        //If there are duplicated chapter, (1.) update its content and (2.) the time of mentioning it.
        void set(int a,int b){
            //conditions:
                //chapter existed-> update
                //chapter not existed
                    //if not full->insert
                    //else flush
        }
        
        //user interface function (2)
        //means that the pop quiz have chapter a . 
        //You need to look for it in the content you memorize. 
        //If it exists, you need to update time of mentioning it   
        int get(int a){
            //if exist return content, and update the node
            //else retun -1
        }


};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b;

    string str1, str2;
    cin >> N >> M;
    

    for (int i = 0; i < M; i++)
    {
        cin >> str1 >> a;
        if (str1.compare("set") == 0)
        {
            cin >> b;

            continue;
        }
        else
        {

        }
    }
    return 0;
}