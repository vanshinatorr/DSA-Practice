/*
Largest Subarray with 0 Sum

Problem:
Find the length of the longest subarray with sum equal to 0.

Approach:
- Use Prefix Sum
- Store the first occurrence of each prefix sum in a HashMap
- If the same prefix sum repeats, the subarray in between has sum 0

Complexity:
- Time: O(n)
- Space: O(n)

Platforms:
- GeeksforGeeks
- LeetCode (325 - Premium)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        
        unordered_map<int,int> mp;
        
        int sum = 0 ; 
        int maxi  = 0 ;
        int n = arr.size() ; 
        
        for(int i = 0;i<n;i++){
            sum+=arr[i]; 
            
            if (sum == 0 ){
                maxi = i+1 ; 
            }
            
            if(mp.find(sum) != mp.end() ){
                maxi = max(maxi , i-mp[sum] );
            }
            else{
                // store first occurrence only
                mp[sum] = i ; 
            }
            
            
        }
        return maxi ; 
    }
}; 
