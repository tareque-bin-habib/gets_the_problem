#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void node_print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void removeAllDuplicates(Node *head)
{
    unordered_set<int> uniqueValues;
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (uniqueValues.count(current->value) > 0)
        {

            previous->next = current->next;
            delete current;
            current = previous->next;
        }
        else
        {

            uniqueValues.insert(current->value);
            previous = current;
            current = current->next;
        }
    }
}

Node *sortTheLinkedList(Node *head)
{
    set<int> sortedValues;
    Node *current = head;
    while (current != NULL)
    {
        sortedValues.insert(current->value);
        current = current->next;
    }

    Node *sortedLinkedList = NULL;
    Node *tail = NULL;
    for (int value : sortedValues)
    {
        Node *newNode = new Node(value);
        if (sortedLinkedList == NULL)
        {
            sortedLinkedList = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return sortedLinkedList;
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

    removeAllDuplicates(head);

    head = sortTheLinkedList(head);

    node_print(head);

    return 0;
}