#include <iostream>
using namespace std;

struct PositionNode
{
    int pos;
    PositionNode *next;
};
void GameMemo(int n)
{
    

    PositionNode *list_head,*cur, *newnode;
    list_head = NULL;

    // init list
    for (int i = 1; i < n + 1; i++)
    {

        newnode = new PositionNode;
        if (!newnode)
            cout << "slot memory fail" << endl;
        newnode->pos = i;
        newnode->next = NULL;
        if (!list_head)
        {
            list_head = newnode;
            cur = list_head;
        }
        else
        {
            cur->next = newnode;
            cur = cur->next;
        }
    }

    cur = list_head;
    while (cur)
    {
        cout << cur->pos << endl;
        cur = cur->next;
    }
}

int main(){
    GameMemo(10);
    return 0;
}