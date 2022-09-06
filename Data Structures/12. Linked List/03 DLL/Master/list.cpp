/*
    Common operations on doubly linked list
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Utility fn
void msg(string str)
{
    cout << str << "\n";
}

// Print list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n\n";
}

// Insert a node in the beginning
Node *insert_front(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

// Insert node at the back
Node *insert_back(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        return newNode;
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    return head;
}

// Delete head
Node *pop_front(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *ptr = head->next;
    ptr->prev = NULL;
    delete head;
    return ptr;
}

// Delete tail
Node *pop_back(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    delete ptr->next;
    ptr->next = NULL;
    return head;
}

// Insert at position
Node *insert_at(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    if (pos == 1 && head == NULL)
        return newNode;
    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node *ptr = head;
    for (int i = 1; i <= pos - 2 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL)
        return head;
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        return head;
    }
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;
    return head;
}

// Search
int search(Node *head, int val)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == val)
            return pos;
        else
        {
            pos++;
            head = head->next;
        }
    }
    return -1;
}

// Driver code
int main()
{
    // Create a new linked list in heap
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Link them
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print list
    msg("Given List");
    printList(head); // 10 20 30

    // Insert front
    head = insert_front(head, 5);
    msg("Insert front (5)");
    printList(head); // 5 10 20 30

    // Insert back
    head = insert_back(head, 35);
    msg("Insert back (35)");
    printList(head); // 5 10 20 30 35

    // Delete front
    head = pop_front(head);
    msg("Delete front");
    printList(head); // 10 20 30 35

    // Delete back
    head = pop_back(head);
    msg("Delete back");
    printList(head); // 10 20 30

    // Insert at position
    head = insert_at(head, 2, 70);
    msg("Insert 70 at pos 2");
    printList(head); // 10 70 20 30

    // Search
    int idx = search(head, 70);
    msg("Search value 70");
    cout << 70 << " found at pos " << idx;
}
