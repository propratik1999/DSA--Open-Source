/*
    Print sum of all subsets of an array
*/

#include <bits/stdc++.h>
using namespace std;

// Function to print sum of all subsets of an array
int subsetSums(int arr[], int n)
{
    // there are total 2^n subsets
    long long size = 1 << n;

    // consider all numbers from 0 to 2^n - 1
    long long sum = 0;
    for (long long i = 0; i < size; i++)
    {
        // init current subset sum
        long long currSum = 0;

        // using binary of current i to decide which elements to pick.
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                currSum += arr[j];

        // total sum
        sum += currSum;
    }

    // answer
    return sum;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << subsetSums(arr, n);
}
