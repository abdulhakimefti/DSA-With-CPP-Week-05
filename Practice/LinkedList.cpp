#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Value;
    Node *Next;
    Node(int val)
    {
        Value = val;
        Next = NULL;
    }
};

void InsertTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (newNode == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void Display(Node *&head)
{

    while (head != NULL)
    {
        cout << head->Value;
        if (head->Next != NULL)
            cout << " -> ";
        head = head->Next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int choice, n, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2:Insertion at Tail" << endl
         << "Choice 3:Insertion at Specific Position" << endl
         << "Choice 4:Search a value (Unique List)" << endl
         << "Choice 5:Search a value (Duplication enable list)" << endl
         << "Choice 6:Insertion after a specific value (Unique list)" << endl
         << "Choice 7:Deletion At head" << endl
         << "Choice 8:Deletion At Tail" << endl
         << "Choice 9:Deletion At Specific Position" << endl
         << "Choice 10:Deletion By value (Unique List)" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Your choice: ";
    cin >> choice;
    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Insert the value in tail: ";
            cin >> n;
            InsertTail(head, n);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    Display(head);
    return 0;
}