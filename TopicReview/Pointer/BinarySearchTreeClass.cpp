#include<iostream>
#include<vector>
using namespace std;

struct node{
    int key;
    node *lchild, *rchild;
};

class BST{

private:
    node* root;
    void insert_recursion(node *cur, int key);
    node* search_recursion(node* cur,int key);
    void inorder_recursion(node* cur);

public:
    BST();
    BST(int key);
    BST(vector<int> key);

    void insert(int key);
    int search(int key);
    void inorder();
    int deleteKey(int key);
};

node* createnode(int key){
    node* newnode=new node;
    newnode->key=key;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}
BST::BST(){root=NULL;};
BST::BST(int key){root=createnode(key);};
BST::BST(vector<int> key)
{
    for (int i = 0; i < key.size(); i++)
    {
        insert(key[i]);
    }
};
void BST::insert_recursion(node *cur, int key){
    
    if (cur->key > key)
    {
        if(cur->lchild)
            insert_recursion(cur->lchild, key);
        else
            cur->lchild = createnode(key);
    }
    else if (cur->key < key)
    {
        if(cur->rchild)
            insert_recursion(cur->rchild, key);
        else
            cur->rchild = createnode(key);
    }
    else if (cur->key == key)
    {
        cout << "already exist" << endl;
        return ;
    }
    return;
};

node* BST::search_recursion(node *cur, int key){
    if (cur == NULL)
        return NULL;
    if (cur->key > key)
    {
        return search_recursion(cur->lchild, key);
    }
    else if (cur->key < key)
    {
        return search_recursion(cur->rchild, key);
    }
    else if (cur->key == key)
    {
        cout << key << " found" << endl;
        return cur;
    }
   
};
void BST::inorder_recursion(node* cur){
    if(!cur) return;

    inorder_recursion(cur->lchild);
    cout << cur->key << " ";
    inorder_recursion(cur->rchild);

};

void BST::inorder(){
    inorder_recursion(root);
};
void BST::insert(int key){
    if(root==NULL){
        root=createnode(key);
        return;
    };
    insert_recursion(root, key);

};
int BST::search(int key){
    if(root==NULL)return -1;
    node *temp = search_recursion(root, key);
    if (!temp)
        return temp->key;
    else return -1;
};

int BST::deleteKey(int key){
    if(root==NULL)return -1;
    node *cur = root;
    while(cur){
        if (cur->key > key)
        {
            cur = cur->lchild;
        }
        else if (cur->key < key)
        {
            cur = cur->rchild;
        }
        else if (cur->key == key)
        {
            break;
        }
    }
    if (cur == NULL)
        return 0;
    if (cur->lchild != NULL && cur->rchild != NULL)
    {

    }
    else if (cur->lchild != NULL)
    {
        
    }
    else if (cur->rchild != NULL)
    {
    }
    else if (cur->lchild == NULL && cur->rchild == NULL)
    {
        delete cur;
    }
};

int main()
{
    BST tree;
    for (int i = 0; i < 10; i++)
    {
        int x=rand()%20;
        cout<<"insert: "<<x<<endl;
        tree.insert(x);
    }
    tree.inorder();
    tree.search(6);
    return 0;
}