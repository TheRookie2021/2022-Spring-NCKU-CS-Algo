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
    int *slots; // for quick searching for block position of slot
    struct PositionNode *list_head;
    struct PositionNode *cur;
    struct BlockNode *temp;

public:
    GameMemo(int n)
    {
        Num = n;
        slots = new int[n + 1]; // discard [0]
        slots[0] = 0;
        slots[1] = 1;
        list_head = new PositionNode;
        list_head->pos = 1;
        list_head->next = NULL;

        list_head->blocklink = new BlockNode;
        list_head->blocklast = list_head->blocklink;
        list_head->blocklink->No = 1;
        list_head->blocklink->nextblock = NULL;
        list_head->blocklink->preblock = NULL;

        cur = list_head;
        // init list
        for (int i = 2; i < n + 1; i++)
        {
            slots[i] = i;
            cur->next = new PositionNode;
            cur = cur->next;
            cur->pos = i;
            cur->blocklink = new BlockNode;
            cur->blocklast = cur->blocklink;
            cur->blocklink->No = i;
            cur->blocklink->nextblock = NULL;
            cur->blocklink->preblock = NULL;
        }
        cur->next = NULL;
    }
    void printGameMemo()
    {
        cur = list_head;
        do
        {
            // print slot
            temp = cur->blocklink;
            cout << cur->pos << ": ";
            // print block
            while (temp)
            {
                cout << temp->No << " ";
                temp = temp->nextblock;
            }
            cout << endl;
            cur = cur->next;
        } while (cur);
    }

    struct PositionNode *SearchSlot(int a)
    {
        cur = list_head;
        while (cur->pos != slots[a])
        {
            cur = cur->next;
        }
        return cur;
    }
    struct BlockNode *SearchNode(int a)
    {

        cur = SearchSlot(a);
        if(!cur->blocklink)
            return NULL;
        temp = cur->blocklink;
        while (temp)
        {
            if(temp->No != a)
                temp = temp->nextblock;
            else return temp;
        }
        return NULL;
        
    }

    void insertBlock(BlockNode *block, int slot)
    {
        // insert block into top of that slot
        if (!block )
            return;
        struct PositionNode *s = SearchSlot(slot);
        
        if(s->blocklast)
        {
            block->preblock = s->blocklast;
            s->blocklast->nextblock = block;
            block->nextblock = NULL;
            s->blocklast = block;
        }else
        {
            block->preblock =NULL;
            block->nextblock = NULL;
            s->blocklast = block;
            s->blocklink = block;
        } 
    }

    void moveOnto(int a, int b)
    {
        if (slots[a] == slots[b])
            return;
        // 1. put the block above a and b back on the top of their original slot
        // 2. update the slots
        // 3. put a onto b
      
        // 1. 2.
        struct PositionNode *sa,*sb;
        struct BlockNode *pa, *pb, *next;
        temp=NULL;
        sa = SearchSlot(a);
        sb = SearchSlot(b);
        pa = SearchNode(a);
        pb = SearchNode(b);
        

        next = pa->nextblock;
        sa->blocklast=pa;
       
        while (next)
        {
            temp = next;
            next = next->nextblock;
            slots[temp->No] = temp->No;
            if(temp->preblock)
            {
                temp->preblock->nextblock=NULL;
            }
            insertBlock(temp,  slots[temp->No]);
        }

        next = pb->nextblock;
        sb->blocklast=pb;
        
        while (next)
        {
          
            temp = next;
            next = next->nextblock;
            slots[temp->No] = temp->No;
            if(temp->preblock)
            {
                temp->preblock->nextblock=NULL;
            }
           insertBlock(temp,  slots[temp->No]);
        }

        // 3.
        slots[a] = slots[b];
        
        if (!pa->preblock)
        {
            sa->blocklink = NULL;
            sa->blocklast = NULL;
        }
        else
        {
            sa->blocklast = pa->preblock;
            pa->preblock->nextblock = NULL;
        }

        insertBlock(pa, slots[a]);
    }

    void moveOver(int a, int b)
    {
         if (slots[a] == slots[b])
            return;
        // 1. put the block above a back on the top of their original slot
        // 2. update the slots
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
            slots[temp->No] = temp->No;
            
            if(temp->preblock)
            {
                temp->preblock->nextblock=NULL;
            }
            insertBlock(temp,slots[temp->No]);
        }
        
        // 3.
        slots[a] = slots[b];
        
        if (!pa->preblock)
        {
            sa->blocklink = NULL;
            sa->blocklast = NULL;
        }
        else
        {
            sa->blocklast = pa->preblock;
            pa->preblock->nextblock = NULL;
        }
        insertBlock(pa, slots[a]);
    }

    void pileOnto(int a, int b)
    {
         if (slots[a] == slots[b])
            return;
        // 1. put the block above b back on the top of their original slot
        // 2. update the slots
        // 3. put a and the block on a onto the top b

        // 1.
        PositionNode *sa, *sb;
        BlockNode *pa, *pb, *next;
        sa = SearchSlot(a);
        sb = SearchSlot(b);
        pa = SearchNode(a);
        pb = SearchNode(b);
        
        next = pb->nextblock;
        sb->blocklast=pb;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            slots[temp->No] = temp->No;
            if(temp->preblock)
            {
                temp->preblock->nextblock=NULL;
            }
           insertBlock(temp, slots[temp->No]);
        }
        // 2.
        next = pa;
        while (next)
        {
            temp = next;
            next = next->nextblock;
            slots[temp->No] = slots[b];
        }
        // 3.
        sb->blocklast->nextblock=pa;
       
        //cout<<sb->blocklast->No<<endl;
        if (!pa->preblock)
        {
            sb->blocklast =  sa->blocklast;
            sa->blocklink = NULL;
            sa->blocklast = NULL;
            
            pa->preblock=pb;
        }
        else
        {
            pa->preblock->nextblock = NULL;
            sb->blocklast =  sa->blocklast;
            sa->blocklast = pa->preblock;
            pa->preblock=pb;
        }
   }

    void pileOver(int a, int b)
    {
        if (slots[a] == slots[b])
            return;
        // 1. put a and the block on a onto the top of slot where b exist
        // 2. update the slots
        // 1.
        PositionNode *sa, *sb;
        BlockNode *pa, *pb, *next,*pre_a;
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
            slots[temp->No] = slots[b];
        }
        // 3.
        sb->blocklast->nextblock=pa;
        pre_a=pa->preblock;
        if (!pre_a)
        {
            pa->preblock=sb->blocklast;
            sa->blocklink = NULL;
            sb->blocklast =  sa->blocklast;
            sa->blocklast = NULL;
        }
        else
        {
            pa->preblock=sb->blocklast;
            sb->blocklast =  sa->blocklast;
            pre_a->nextblock = NULL;
            sa->blocklast = pre_a;
            
        }
       
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b;

    string str1, str2;
    cin >> N >> M;
    GameMemo game(N);
    //game.printGameMemo();

    for (int i = 0; i < M; i++)
    {
        cin >> str1 >> a >> str2 >> b;
        //cout<< str1 <<" "<<a<<" " <<str2<<" " <<b<<endl;
        if (str1.compare("move")==0 && str2.compare("onto")==0)
        {
            //cout<<"move"<<a<<"onto"<< b <<endl;
            game.moveOnto(a, b);
            continue;
        }
        if (str1.compare("move")==0 && str2.compare("over")==0)
        {
            
            //cout<<"move"<<a<<"over"<<b<<endl;
            game.moveOver(a, b);
            continue;
        }
        if (str1.compare("pile")==0 && str2.compare("onto")==0)
        {
            
            //cout<<"pile"<<a<<"onto"<<b<<endl;
            game.pileOnto(a,b);
            continue;
        }
        if (str1.compare("pile") ==0&& str2.compare("over")==0)
        {
            
            //cout<<"pile"<<a<<"over"<<b<<endl;
            game.pileOver(a,b);
        }
    }
    game.printGameMemo();
    return 0;
}