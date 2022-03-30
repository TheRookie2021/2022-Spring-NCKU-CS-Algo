#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;

class StackDS
{
private:
    stack<set<string>> s;

public:
    int Stack_size()
    {
        return s.size();
    }
    // PUSH，put the empty set {} into stack
    void PUSH()
    {
        set<string> temp;
        s.push(temp);
        cout << s.top().size() << endl;
    };

    // DUP，duplicate the top element of the stack and put it in stack
    void DUP()
    {
        set<string> temp;
        temp = s.top();
        s.push(temp);
        cout << s.top().size() << endl;
    };

    // UNION，pop out two elements, put the union of them back to stack
    void UNION()
    {
        set<string> temp1, temp2;
        temp1 = s.top();
        s.pop();
        temp2 = s.top();
        s.pop();
        // union
        set<string>::iterator it2;
        for (it2 = temp2.begin(); it2 != temp2.end(); it2++)
        {
            temp1.insert(*it2);
        }
        s.push(temp1);
        cout << s.top().size() << endl;
    };
    // INTERSECT，pop out two elements, put the intersection of them back to stack
    void INTERSECT()
    {
        set<string> temp1, temp2, intersect;
        temp1 = s.top();
        s.pop();
        temp2 = s.top();
        s.pop();
        // intersect
        set<string>::iterator it2;
        for (it2 = temp2.begin(); it2 != temp2.end(); it2++)
        {
            // if found=>intersect of both
            if (!(temp1.find(*it2) == temp1.end()))
            { // why can't i use ==NULL?
                intersect.insert(*it2);
            }
        }
        s.push(intersect);
        cout << s.top().size() << endl;
    };
    // ADD，pop out two elements,
    // add the first as the element of the later,
    // and put the result back to the stack.
    void ADD()
    {
        set<string> temp1, temp2;
        temp1 = s.top();
        s.pop();
        temp2 = s.top();
        s.pop();

        // add the first as the element of the later
        string final_str, temp_str;
        set<string>::iterator it1;
        final_str.append("{");
        for (it1 = temp1.begin(); it1 != temp1.end(); it1++)
        {
            final_str.append(*it1);
        }
        final_str.append("}");
        temp2.insert(final_str);
        s.push(temp2);
        cout << s.top().size() << endl;
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string str1;
    StackDS test;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str1;
        if (str1.compare("PUSH") == 0)
        {
            test.PUSH();
            continue;
        }
        if (str1.compare("DUP") == 0)
        {
            test.DUP();
            continue;
        }
        if (str1.compare("UNION") == 0)
        {
            test.UNION();
            continue;
        }
        if (str1.compare("INTERSECT") == 0)
        {
            test.INTERSECT();
            continue;
        }
        if (str1.compare("ADD") == 0)
        {
            test.ADD();
        }
    }

    return 0;
}