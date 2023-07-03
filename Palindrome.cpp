#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

bool Palindrome(Node *head)
{
    vector<int> values;
    Node *current = head;

    while (current != NULL)
    {
        values.push_back(current->val);
        current = current->next;
    }

    int start = 0;
    int end = values.size() - 1;

    while (start < end)
    {
        if (values[start] != values[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int value;
    while (cin >> value && value != -1)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (Palindrome(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}