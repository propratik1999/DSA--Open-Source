/*
    Insert a node at the beginning of a circular doubly linked list
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Insert at head
Node *insertAtHead(Node *head, int val)
{
    // create new node
    Node *newHead = new Node(val);

    // if list is empty
    if (head == NULL)
    {
        newHead->next = newHead;
        newHead->prev = newHead;
        return newHead;
    }

    // adjust links
    newHead->prev = head->prev;
    newHead->next = head;
    head->prev->next = newHead;
    head->prev = newHead;

    // return
    return newHead;
}

// Print list
void printlist(Node *head)
{
    // if list is empty
    if (head == NULL)
        return;

    // print logic
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);

    // newline
    cout << "\n";
}

// Driver code
int main()
{
    // Create a circular doubly linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Link them
    head->next = second;
    second->next = third;
    third->next = head;
    second->prev = head;
    third->prev = second;
    head->prev = third;

    // Print
    printlist(head);

    // fn call
    head = insertAtHead(head, 5);

    // Print
    printlist(head);
}
