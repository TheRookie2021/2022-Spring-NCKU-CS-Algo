# passing pointer/ address of pointer in a function 
!!FORGET ABOUT PASSING BY REFERENCE OR PASSING BY VALUE!!  

When using a function, it does not verify what kind of passing method it is using, it is all the same to a function.  

What seperates these two passing concepts is whether the function is manipulating an address or not.  
In general, a function always passing a copy of the variable, and the manipulation in a function can only base on the copy it recieves.  
  
Thus, what makes function a "pass by value" or "pass by ref" depends on the kind of data it recieves:  
- if a function recieves a copy of (int), it manipulates the data of that copy.  
- if a function recieves a copy of (int*), which means it recieves an copy of an address, it manipulates the data based on the address. 
    
futher Q: how "delete" works in a function? 

# BST in C++ class 
    - if we attempt to hide the manipulation of link and node to the user, we have to write two function as a pair for this implementation, one for public member function and the other for private one.
        - public : act as a wrapper, showed to user, the user has no need to worry about the pointer or node*  or something.
        - private: the function with recursive calls.
    - version from geekforgeeks
    ```
    // C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else if (value < root->data){
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}

// This code is contributed by pkthapa

    ```