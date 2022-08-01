#include<iostream>
using namespace std;
int size;
typedef struct stacknode *stackptr;
struct stacknode
{
    char data;
    stackptr p;
};

stackptr creatnode(char a)
{
    stackptr newnode = new stacknode;
    newnode->data = a;
    newnode->p = NULL;
    return newnode;
}

void push(stackptr *head, char a)
{
    if (*head == NULL)
    {
        *head = creatnode(a);
        return;
    }
    stackptr cur = (*head);
    *head = creatnode(a);
    (*head)->p = cur;
}
bool detectPalindrom(stackptr forward,stackptr backward){
    stackptr fcur=forward,bcur=backward;
    while(fcur){
        if(fcur->data!=bcur->data)return false;
        fcur=fcur->p;
        bcur=bcur->p;
    }
    return true;

}

int main(){
    stackptr forward=NULL, backward=NULL;
    char str[30];
    size=0;
    cin>>str;
    while(str[size]!='\0')size++;
    cout<<size<<" \n";

    for (int i = 0; i < size; i++)
    {
        push(&forward,str[i]);
        push(&backward,str[size-i-1]);
    }
    cout<<detectPalindrom(forward,backward);
    return 0;
}