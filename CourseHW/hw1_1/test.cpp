#include <iostream>
#include <string>
using namespace std;

struct BlockNode
{
    int No;
    struct BlockNode *nextblock;
    struct BlockNode *preblock;
};

struct PositionNode
{
    int pos;
    struct BlockNode *blocklink;
    struct BlockNode *blocklast;
    struct PositionNode *next;
};
// typedef PositionNode* PosList;

class GameMemo
{
private:
    int Num;
    int *arr; // for quick searching for block position of slot
    struct PositionNode *list_head;
    
    struct BlockNode *temp;

public:
    GameMemo(int n)
    {
        Num = n;
        //why this will cause seg fault and data overwrite?
        //ans you should use [] instead of ()
        arr = new int[n + 1]; // discard [0]
        
        
/*
        list_head->blocklink = new BlockNode;
        list_head->blocklast = list_head->blocklink;
        list_head->blocklink->No = 1;
        list_head->blocklink->nextblock = NULL;
        list_head->blocklink->preblock = NULL;
*/

        struct PositionNode *cur,*newnode;
        list_head=NULL;
        
        // init list
        for (int i = 1; i < n + 1; i++)
        {
           
           arr[i] = i;
            newnode= new struct PositionNode;
            if(!newnode) cout<<"slot memory fail"<<endl;
            newnode->pos = i;
            newnode->next=NULL;
            if(!list_head){
                list_head=newnode;
                cur=list_head;
            } 
            else
            {
                cur->next = newnode;
                cur = cur->next;
            }
/*
            cur->blocklink = new BlockNode;
            if(!cur->blocklink)cout<<"block memory fail"<<endl;
            cur->blocklast = cur->blocklink;
            cur->blocklink->No = i;
            cur->blocklink->nextblock = NULL;
            cur->blocklink->preblock = NULL;
*/

        }
        
        cur = list_head;
        while (cur)
        {
            cout<<cur->pos<<endl;
            cur=cur->next;
        } 
    }
    void printGameMemo()
    {
        struct PositionNode *cur;
        cur = list_head;
        while (cur)
        {
            cout<<cur->pos<<endl;
            cur=cur->next;
        } 

            /*
        do
        {
            // print slot
            cout << cur->pos << ": ";
            temp = cur->blocklink;
            // print block
            while (temp)
            {
                cout << temp->No << " ";
                temp = temp->nextblock;
            }
            cout << endl;
            cur = cur->next;
        } while (cur);
            */
    }

    struct PositionNode *SearchSlot(int a)
    {
        if (a > Num || a < 1)
            return NULL;
        struct PositionNode *cur;
        cur = list_head;
        while (cur->pos != arr[a])
        {
            cur = cur->next;
        }
        return cur;
    }

    struct BlockNode *SearchNode(int a)
    {
        if (a > Num || a < 1)
            return NULL;
        struct PositionNode *cur;
        cur = SearchSlot(a);

        temp = cur->blocklink;
        while (temp->No != a)
        {
            temp = temp->nextblock;
        }
        return temp;
    }
    void insertBlock(BlockNode *block, int slot)
    {
        // insert block into top of that slot
        if (!block)
            return;
        struct PositionNode *s = SearchSlot(slot);
        s->blocklast->nextblock = block;
        block->preblock = s->blocklast;
        block->nextblock = NULL;
        s->blocklast = block;
    }
    void moveOnto(int a, int b)
    {
        if (a == b)
            return;
        // 1. put the block above a and b back on the top of their original slot
        // 2. update the arr
        // 3. put a onto b

        // 1. 2.
        PositionNode *sa;
        BlockNode *pa, *pb, *next;
        sa = SearchSlot(a);

        pa = SearchNode(a);
        pb = SearchNode(b);

        next = pa->nextblock;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = temp->No;
            insertBlock(temp, temp->No);
        }
        next = pb->nextblock;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = temp->No;
            insertBlock(temp, arr[temp->No]);
        }
        // 3.
        arr[a] = arr[b];
        sa->blocklast = pa->preblock;
        if (pa->preblock)
            pa->preblock->nextblock = NULL;

        insertBlock(pa, arr[b]);
    }

    void moveOver(int a, int b)
    {
        if (a == b)
            return;
        // 1. put the block above a back on the top of their original slot
        // 2. update the arr
        // 3. put a onto the top of slot where b exist

        // 1.
        PositionNode *sa;
        BlockNode *pa, *pb, *next;
        sa = SearchSlot(a);

        pa = SearchNode(a);
        pb = SearchNode(b);

        next = pa->nextblock;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = temp->No;
            insertBlock(temp, temp->No);
        }
        // 3.
        arr[a] = arr[b];
        sa->blocklast = pa->preblock;
        if (pa->preblock)
            pa->preblock->nextblock = NULL;

        insertBlock(pa, arr[b]);
    }
    void pileOnto(int a, int b)
    {
        if (a == b)
            return;
        // 1. put the block above b back on the top of their original slot
        // 2. update the arr
        // 3. put a and the block on a onto the top b

        // 1.
        PositionNode *sa, *sb;
        BlockNode *pa, *pb, *next;
        sa = SearchSlot(a);
        sb = SearchSlot(b);
        pa = SearchNode(a);
        pb = SearchNode(b);

        next = pb->nextblock;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = temp->No;
            insertBlock(temp, temp->No);
        }
        // 2.
        next = pa;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = arr[b];
        }
        // 3.
        pb->nextblock = pa;
        sb->blocklast = sa->blocklast;
        sa->blocklast = pa->preblock;
        pa->preblock = pb;
    }
    void pileOver(int a, int b)
    {
        if (a == b)
            return;
        // 1. put a and the block on a onto the top of slot where b exist
        // 2. update the arr
        // 1.
        PositionNode *sa, *sb;
        BlockNode *pa, *pb, *next;
        sa = SearchSlot(a);
        sb = SearchSlot(b);
        pa = SearchNode(a);
        pb = SearchNode(b);
        // 2.
        next = pa;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            arr[temp->No] = arr[b];
        }
        // 3.
        pb->nextblock = pa;
        sb->blocklast = sa->blocklast;
        sa->blocklast = pa->preblock;
        pa->preblock = pb;
    }
};

int main()
{
    int N, M, a, b;

    string str1, str2;
    GameMemo game(8);
    game.printGameMemo();

    return 0;
}