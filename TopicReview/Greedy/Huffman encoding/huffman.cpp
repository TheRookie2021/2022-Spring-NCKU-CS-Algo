#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution
{
    struct node
    {
        string c;
        int w;
        struct node *left, *right; // left ptr=0; right ptr=1

        // for internal node: c set null, w is the sum of the children's weight
        // for external node: c is the character, w is the weight
    };
    struct tree
    {
        struct node *head;
    };

public:
    bool operator()(node *a, node *b)
    {
        return (a->w > b->w);
    }
    void preorder(node *root, string &buffer, int counter, vector<string> &output)
    {
        if (root == NULL)
        {
            return;
        }
        // if (!root->c.empty())
        //     cout << root->c<<" ";
        // else

        if (root->left != NULL)
        {
            buffer[counter] = '0';
            preorder(root->left, buffer, counter + 1, output);
        }

        if (root->right != NULL)
        {
            buffer[counter] = '1';
            preorder(root->right, buffer, counter + 1, output);
        }

        // cout<<buffer.substr(0, counter)<<" ";
        if (!root->c.empty())
        {
            // cout << root->c << " ";
            output.push_back(buffer.substr(0, counter));
        }
        // else cout<<"non"<<root->w<<" ";
    }
    vector<string>  huffmanCodes(string S, vector<int> f, int N)
    {

        vector<string> output;
        tree t;
        t.head = 0;
        // preprocess input
        priority_queue<node *, vector<node *>, Solution> pq;
        for (int i = 0; i < N; i++)
        {
            node *temp = new node;
            temp->c = S[i];
            temp->w = f[i];
            pq.push(temp);
        }
        // build tree
        while (1)
        {
            if (pq.size() == 1)
            {
                t.head = pq.top();
                pq.pop();
                break;
            }
            node *a = pq.top();
            pq.pop();
            node *b = pq.top();
            pq.pop();

            // merge
            node *internal = new node;
            internal->left = a;
            internal->right = b;
            internal->w = a->w + b->w;
            pq.push(internal);
        }

        // traverse tree( preorder)
        string buffer( N, 'x');
        preorder(t.head, buffer, 0, output);
        // cout << "output: \n";
        for (int i = 0; i < N; i++)
        {
            cout << output[i] << " ";
        }
        return output;
    }
};

int main()
{

    int n;
    string str;
    vector<int> weight;
    vector<string> output;

    cin >> str;
    n = str.size();
    weight.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    Solution ans;
    ans.huffmanCodes(str, weight, n);

    return 0;
}