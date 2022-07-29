#include <iostream>
using namespace std;

typedef struct node* nodeptr;// 簡化寫法用
struct node{
    int data;
    nodeptr lc, rc;
};
//Q: how a function with parameter works in c ?
//A: the function passes the copy of the variable(dosen't matter what type of data it pass) to another space, 
//      and modify that copy(concept: pass by value), or do anything based on the copy(concept: pass by ref)
// is it correct?

// this doesn't work: 
// this function passing the ptr of a node, and modify the pointer itself
// (pass a pointer but change the pointer instead of the value stored in the address)
void addnode_ptr(nodeptr root, int data){
    if(root==NULL){
        nodeptr newnode=new node;
        newnode->data=data;
        newnode->lc=NULL;
        newnode->rc=NULL;
        root= newnode;
        return;
    }
    if(root->data>data){
        addnode_ptr(root->lc,data);
    }else{
        addnode_ptr(root->rc,data);
    }
}

// this works
void addnode_ptrptr(nodeptr *root, int data){
    if (*root == NULL)
    {       
        nodeptr newnode = new node; 
        newnode->data = data;
        newnode->lc = NULL;
        newnode->rc = NULL;
        *root = newnode;
        return;
    }
    if ((*root)->data > data)
    {
        addnode_ptrptr( &((*root)->lc), data);
    }
    else
    {
        addnode_ptrptr(&(*root)->rc, data);
    }
}

void preorder(nodeptr root){
    if(root==NULL) {
        return;
    }
    cout << root->data<<" ";
    preorder(root->lc);
    preorder(root->rc);

}

void modify_node_passing_ptr(nodeptr root){
    cout<<"current data: "<<root->data<<endl;
    cout << "modify node pointed by pointer by passing the pointer. to 100\n";

    root->data=100;
}

void modify_pointer_passing_ptr(nodeptr root){
    cout<<"current data: "<<root->data<<endl;
    cout << "modify pointer by passing the pointer. to 200\n";
    // delete root; // this only delete "a node", so there may leave some dangling pointers/nodes)

    // assign a new pointer
    nodeptr newnode = new node;
    newnode->data = 200;
    newnode->lc = NULL;
    newnode->rc = NULL;
    root = newnode;
}
void modify_pointer_passing_ptraddr(nodeptr *root)
{
    
    cout<<"current data: "<<(*root)->data<<endl;
    cout << "modify pointer by passing address of pointer. to 300\n";
    // delete root; // this only delete "a node", so there may leave some dangling pointers/nodes)

    // assign a new pointer
    nodeptr newnode = new node;
    newnode->data = 300;
    newnode->lc = NULL;
    newnode->rc = NULL;
    *root = newnode;
}

int main(){
    nodeptr ra,rb;
    ra = NULL;
    rb = NULL;

    // randomly add node to BST by different methods
    // to test differences between passing pointer and passing address of pointer behavior in a function
    for(int i =0;i<5;i++){
        int x=rand()%10;
        cout<<x<<" \n";
        addnode_ptr(ra,x);
        addnode_ptrptr(&rb,x);
    }

    cout<<endl;
    cout<<"preorder:\nra: ";
    preorder(ra);
    cout<<endl<<"rb: ";
    preorder(rb);
    cout<<endl;

    cout << "=======================================\n";
    
    // futher testing among different modification on different parts:

    cout<<"rb root: "<<rb->data<<endl;
    int original=rb->data;
    modify_node_passing_ptr(rb);
    if(original!=rb->data)cout<<"---modify successfully---\n";
    else cout<<"---modify failed---\n";
    cout<<"rb root after modify_node_passing_ptr : "<<rb->data<<endl<<endl;
     
    
    original=rb->data;
    modify_pointer_passing_ptr(rb);
    if(original!=rb->data)cout<<"---modify successfully---\n";
    else cout<<"---modify failed---\n";
    cout<<"rb root after modify_pointer_passing_ptr : "<<rb->data<<endl<<endl;
    

    original=rb->data;
    modify_pointer_passing_ptraddr(&rb);
    if(original!=rb->data)cout<<"---modify successfully---\n";
    else cout<<"---modify failed---\n";
    cout<<"rb root after modify_pointer_passing_ptraddr : "<<rb->data<<endl<<endl;
    

    // bug: whyyyyy delete works in a function even if it's pass by value?
    return 0;
}