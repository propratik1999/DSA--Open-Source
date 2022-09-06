//  https://www.gfirstksforgfirstks.org/pair-in-cpp-stl/

#include <bits/stdc++.h>
using namespace std;

/* ========== Basics of pair ========== */
void basics()
{
    // init pair
    pair<int, char> pair;

    pair.first = 1;              // assign first value
    pair.second = 'a';           // assign second value
    cout << pair.first << " ";   // output pair.first
    cout << pair.second << "\n"; // output pair.second
}

/* ========== Different types of initialization of pair ========== */

void init()
{
    // 1. default initialization
    pair<int, int> p1;

    // 2. initialize while declaring
    pair<int, char> p2(2, 'b');

    // 3. using make_pair function
    pair<int, int> p3;
    p3 = make_pair(10, 100);

    // 4. using another pair
    pair<int, int> p4(p3);
}

/* ========== Operations on pair ========== */
// 1. swap
void swapPair()
{
    pair<char, int> p1 = make_pair('A', 1);
    pair<char, int> p2 = make_pair('B', 2);
    swap(p1, p2);
    cout << p1.first << " " << p1.second << " \n"; // (B,2)
    cout << p2.first << " " << p2.second << " \n"; // (A,1)
}

// 2. comparision
void compare()
{
    pair<char, int> p1 = make_pair(1, 2);
    pair<char, int> p2 = make_pair(100, 200);
    cout << (p1 == p2) << "\n"; // false (all values must be equal)
    cout << (p1 != p2) << "\n"; // true  (if any value is not equal)
    cout << (p1 >= p2) << "\n"; // false (if first is >= return true otherwise check second)
    cout << (p1 <= p2) << "\n"; // true  (if first is <= return true otherwise check second)
    cout << (p1 > p2) << "\n";  // false (if first is > return true otherwise check second)
    cout << (p1 < p2) << "\n";  // true  (if first is < return true otherwise check second)
}

/* ========== Tuple ========== */
void tuple_fn()
{
    // 1. Declaration
    int integer;
    bool boolean;
    char character;
    double floating;

    // using make_tuple() to initialize
    tie(integer, boolean, character, floating) = make_tuple(10, true, 'n', 40.23);
    cout << integer << " " << boolean << " " << character << " " << floating << "\n";

    // 2. swap
    int first = 1, second = 2;

    // using make_tuple() to swap
    tie(first, second) = make_tuple(second, first);
    cout << first << " " << second;
}

// Driver code
int main()
{
    // run any fn
    swapPair();
}