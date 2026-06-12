/*
===============================================================================
File Name    : leaders_in_array.cpp
https://www.naukri.com/code360/problems/leaders-in-an-array_873144?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM
Problem      : Leaders in an Array
Platform     : Code360 / GFG
Difficulty   : Easy
===============================================================================

Problem:
Given an array, return all leaders.

A leader is an element such that there is no greater element on its right side.

Example:
Input  : [16, 17, 4, 3, 5, 2]
Output : [17, 5, 2]

===============================================================================
Approach (Optimal - Right to Left Traversal)

Key Observation:
For an element to be a leader, it must be greater than every element on its
right side.

Instead of checking every element's right side (O(n²)),
we maintain the maximum element seen so far while traversing from right to left.

Flow:
1. Start from the last element.
2. Maintain maxSoFar.
3. If current element > maxSoFar:
      - It is a leader.
      - Add it to answer.
      - Update maxSoFar.
4. Since leaders are collected in reverse order,
   reverse the answer vector before returning.

===============================================================================
Why It Works

At any index i:

maxSoFar = maximum element present on the right side of i

If:
    elements[i] > maxSoFar

Then no element on the right is greater than elements[i],
therefore elements[i] is a leader.

===============================================================================
Complexity

Time Complexity  : O(n)
Space Complexity : O(n)   // Answer vector

===============================================================================
==================================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &elements, int n)
{
    int maxSoFar = INT_MIN;
    vector<int> leaders;

    for (int i = n - 1; i >= 0; i--)
    {
        if (elements[i] > maxSoFar)
        {
            leaders.push_back(elements[i]);
            maxSoFar = elements[i];
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}
