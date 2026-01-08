// LeetCode 15 - 3Sum
// Approach: Sorting + Two Pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding answer vector)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and apply two pointers
        for(int i = 0; i < n - 2; i++) {

            // Skip duplicate fixed elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;        // Need a bigger sum
                }
                else if(sum > 0) {
                    k--;        // Need a smaller sum
                }
                else {
                    // Valid triplet found
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
