#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val){
        value = val;
        next= NULL;
    }
   
};
struct Test
{
    int position[1000];
};
void InsertTail(Node *&head, int val);
void InsertHead(Node *&head, int val);
void InsertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int val);
void searchByDuplicate(Node *&head, int val);
Test searchByDuplicateReturn(Node *&head, int val);
void searchByValueUniueAndInsert(Node *&head, int searchValue, int val);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int val);
Node *reverseNonRecursive(Node *&head);
void display(Node *n);
int countLength(Node *Head);
void InsertTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void InsertionAtSpecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;

        count++;
    }
    return count;
}
void searchByDuplicate(Node *&head, int val)
{
    Node *temp = head;
    int size = countLength(head);
    int position[size + 1], k = 1;

    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == val)
        {
            // cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        count++;
        temp = temp->next;
    }
    cout << endl;
    if (flag == 0)
        cout << "The search value is not found" << endl;
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << " , ";
        }
    }
}
Test searchByDuplicateReturn(Node *&head, int val)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == val)
        {
            T.position[k] = count;
            k++;
        }
        count++;
        temp = temp->next;
    }

    T.position[0] = k;
    return T;
}
void searchByValueUniqueAndInsert(Node *&head, int searchValue, int val)
{
    // Step 1 : Search the position of the search value;
    int position = searchByValueUnique(head, searchValue);
    // Step 2 : insert the value at the position+1;
    InsertionAtSpecificPosition(head, position + 1, val);
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        // Head is null
        if (temp == NULL)
        {
            cout << "There is no value in the linked List" << endl;
        }
        // Head is  tail
        else
        {
            cout << "There is no value in the linked List" << endl;
        }
    }
}
void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            Node *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
    else
    {
        // Position out of range
        if (position > countLength(head))
        {
            cout << "Position is out of bound" << endl;
        }

        else
        {
            // LL is NULL
            cout << "There is no value in linked list" << endl;
        }
    }
}
void deletionByValueUnique(Node *&head, int val)
{
    // Find the position of the value
    int position = searchByValueUnique(head, val);
    // Delete the node at the position
    deletionAtSpecificPosition(head, position);
}
Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;

    if (head == NULL)
    {
        return head;
    }

    Node *Next = head->next;

    while (true)
    {
        current->next = prev;
        prev = current;
        current = Next;
        if (current == NULL)
            break;
        Next = Next->next;
    }
    return prev;
}
int countLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        if (n->next != NULL)
            cout << " -> ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n, position;
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
         << "Choice 11:Reversal of linked list (Non-Recursive)" << endl
         << "Choice 0: Exit" << endl;
    int choice = 2;
    while (choice != 0)
    {
        cout << endl;
        cout << "Next Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> n;
            InsertHead(head, n);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> n;
            InsertTail(head, n);
            break;
        case 3:
            cout << "Enter the desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> n;
            InsertionAtSpecificPosition(head, position, n);
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> n;
            position = searchByValueUnique(head, n);
            if (position != -1)
            {
                cout << "The number is at position " << position << endl;
            }
            else
            {
                cout << "The number is not yet found" << endl;
            }
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> n;
            cout << "The number is at position ";
            Test T;
            T = searchByDuplicateReturn(head, n);
            if (T.position[0] == 1)
            {
                cout << "The number is not yet found" << endl;
            }
            else
            {
                int size = T.position[0];
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << " , ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> n;
            searchByValueUniqueAndInsert(head, searchValue, n);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            int position;
            cout << "Enter the Desired Position to delete: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            cout << endl;
            display(head);
            break;
        case 10:

            cout << "Enter the Desired value to delete: ";
            cin >> n;
            deletionByValueUnique(head, n);
            cout << endl;
            display(head);
            break;
        case 11:
            head = reverseNonRecursive(head);
            display(head);
            break;
        default:
            break;
        }
    }
  

    cout << "Linked List : ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}