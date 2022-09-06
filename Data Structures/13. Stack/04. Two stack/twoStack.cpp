/*
    Create a data structure twoStacks that represents, well, two stacks.
    Implementation of twoStacks should use only one array, i.e., both 
    stacks should use the same array for storing elements.

    push1(int x) –> pushes x to first stack 
    push2(int x) –> pushes x to second stack
    pop1() –> pops an element from first stack and return the popped element 
    pop2() –> pops an element from second stack and return the popped element
    Implementation of twoStack should be space efficient.
*/

#include <bits/stdc++.h>
using namespace std;

// Struct with constructor
struct TwoStacks
{
    // int pointer for dynamic alloc
    int *arr;

    // capacity of array
    int cap;

    // top1 = -1 (before first), top2 = cap (after last)
    int top1, top2;

    // init constructor
    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = -1;
        top2 = cap;
    }

    // push in first stack
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow";
            exit(1);
        }
    }

    // push in second stack
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow";
            exit(1);
        }
    }

    // pop in first stack
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }

    // pop in second stack
    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
};

// Driver code
int main()
{
    // Initialize
    TwoStacks tstk(5);

    // Push elements in both stack
    tstk.push1(5);
    tstk.push2(10);
    tstk.push2(15);
    tstk.push1(11);
    tstk.push2(7);

    // Pop from stk 1
    cout << "Popped element from stack1 is " << tstk.pop1();

    // Pop from stk 2
    cout << "\nPopped element from stack2 is " << tstk.pop2();
}
