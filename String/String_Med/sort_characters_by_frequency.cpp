// File: frequency_sort_bucket.cpp
// Problem: LeetCode 451 - Sort Characters By Frequency
// Approach: Bucket Sort + Hash Map
// Author: Vansh (Git Version)

/*
-------------------------------------------------------
Problem
Given a string s, sort it in decreasing order
based on frequency of characters.

Example:
Input:  "tree"
Output: "eert" or "eetr"
-------------------------------------------------------

Approach (Bucket Sort)
1. Count frequency of each character using unordered_map.
2. Create buckets where index = frequency.
   bucket[i] stores characters appearing i times.
3. Traverse buckets from high frequency to low.
4. Add each character i times into answer.

Why Bucket Sort?
- Max frequency can be n (string length)
- We use frequency as direct index.

-------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)
-------------------------------------------------------

Mistakes / Important Notes
- bucket size = s.size() + 1
- Loop from s.size() down to 1
- Use:
    ans += string(i, c);

  string(i,c) means:
  repeat character c, i times

Example:
string(3,'a') => "aaa"
-------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Frequency Count
        unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }

        // Step 2: Buckets
        // index = frequency
        vector<string> bucket(s.size() + 1);

        for(auto p : mp){
            bucket[p.second] += p.first;
        }

        // Step 3: Build answer from high freq to low
        string ans = "";

        for(int i = s.size(); i >= 1; i--){

            for(char c : bucket[i]){

                // repeat c i times
                ans += string(i, c);
            }
        }

        return ans;
    }
};
