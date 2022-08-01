#include <iostream>
using namespace std;
// notice: delete the first element should be served as a special condition
typedef struct linknode *linkptr;
struct linknode
{
    int data;
    linkptr p;
};

linkptr creatnode(int a)
{
    linkptr newnode = new linknode;
    newnode->data = a;
    newnode->p = NULL;
    return newnode;
}

void pushback(linkptr *head, int a)
{
    if (*head == NULL)
    {
        *head = creatnode(a);
        return;
    }
    linkptr cur = (*head);
    while (cur->p)
    {
        cur = cur->p;
    }
    cur->p = creatnode(a);
}

void deleteData(linkptr *head, int a)
{
    linkptr cur = *head, prev = *head;
    while(cur){
        if(cur->data==a){
            if(cur==*head)
                *head = (*head)->p; // why can't "prev=prev->p;"??
            else
                prev->p = cur->p;
            
            cout << cur->data << " deleted\n";
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->p;
    }
    cout<<"no such data\n";

}

void deleteOrder(linkptr *head, int a)
{
    linkptr cur = *head, prev=*head;
    while(cur->p){
        if(a==1){
            break;
        }else a--;
        prev=cur;
        cur=cur->p;
    }
    if(a==1){
        if (cur == *head)
            *head = (*head)->p; // why can't "prev=prev->p;"??
        else
            prev->p = cur->p;
        cout << cur->data << " deleted\n";
        delete cur;
    }
    else
        cout << "not that long\n";
}

void insertData(linkptr*head,int a,int place){
    linkptr cur = *head, prev=*head;
    while(cur->p){
        if(place==1){
            break;
        }else place--;
        prev=cur;
        cur=cur->p;
    }
    if (place == 1)
    {
        prev->p =creatnode(a);
        prev=prev->p;
        prev->p=cur;
        cout << prev->data << " inserted\n";

    }
    else
        cout<<"too short, pushback:"<<a<<endl,pushback(head,a);
    
}

void printlist(linkptr head)
{
    cout<<"list: ";
    if (head == NULL)
        cout << "nothing";
    linkptr cur = head;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->p;
    }
    cout << endl;
}

int main()
{
    linkptr head = NULL;
    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 10;
        cout <<"pushback: "<< x << " ";
        pushback(&head, x);
    }
    cout << endl;
    printlist(head);
    deleteOrder(&head,3);
    printlist(head);
    deleteOrder(&head,5);
    printlist(head);
    insertData(&head,50,2);
    printlist(head);
    insertData(&head,20,20);
    printlist(head);
    deleteData(&head,20);
    printlist(head);
    deleteData(&head,3);
    printlist(head);
    deleteOrder(&head, 1);
    printlist(head);
    return 0;
}