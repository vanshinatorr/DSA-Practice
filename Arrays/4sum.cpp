// LeetCode 18 - 4Sum
// Approach: Sorting + Two Loops + Two Pointers
// Time Complexity: O(n^3)
// Space Complexity: O(1) (excluding output)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        // Edge case
        if (n < 4) return ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix first element
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Fix second element
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate values for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1;
                int r = n - 1;

                // Step 4: Two-pointer approach
                while (l < r) {

                    long long sum =
                        (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        // Skip duplicate values for l and r
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sum < target) {
                        l++;   // Need a larger sum
                    }
                    else {
                        r--;   // Need a smaller sum
                    }
                }
            }
        }
        return ans;
    }
};
