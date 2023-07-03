#include <bits/stdc++.h>
using namespace std;
class LinkedListNode
{
public:
    int value;
    LinkedListNode *prev;
    LinkedListNode *next;

    LinkedListNode(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    LinkedListNode *head;
    LinkedListNode *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int index, int value)
    {
        LinkedListNode *newNode = new LinkedListNode(value);

        if (index == 0)
        {
            newNode->next = head;
            if (head != NULL)
                head->prev = newNode;
            head = newNode;
            if (tail == NULL)
                tail = newNode;
        }
        else
        {
            LinkedListNode *currentNode = head;
            int currentIndex = 0;

            while (currentNode != NULL && currentIndex < index)
            {
                currentNode = currentNode->next;
                currentIndex++;
            }

            if (currentNode != NULL)
            {
                newNode->next = currentNode;
                newNode->prev = currentNode->prev;
                if (currentNode->prev != NULL)
                    currentNode->prev->next = newNode;
                currentNode->prev = newNode;
                if (currentNode == head)
                    head = newNode;
            }
            else
            {
                if (currentIndex == index)
                {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                else
                {
                    cout << "Invalid" << endl;
                    delete newNode;
                    return;
                }
            }
        }

        printListLeftToRight();
        printListRightToLeft();
    }

    void printListLeftToRight()
    {
        LinkedListNode *currentNode = head;

        cout << "L -> ";
        while (currentNode != NULL)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void printListRightToLeft()
    {
        LinkedListNode *currentNode = tail;

        cout << "R -> ";
        while (currentNode != NULL)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->prev;
        }
        cout << endl;
    }
};

int main()
{
    int Q;
    cin >> Q;

    DoublyLinkedList linkedList;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        linkedList.insertNode(X, V);
    }
    return 0;
}