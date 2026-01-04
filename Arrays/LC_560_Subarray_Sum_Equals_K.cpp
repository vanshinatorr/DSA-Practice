// LeetCode 560 - Subarray Sum Equals K
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int , int > mpp ; // count and frequency 

        int count = 0 ;
        int presum = 0 ; 
        mpp[0] = 1  ;

        for(int i = 0 ; i < nums.size() ; i ++){
          presum += nums[i] ; 
          int remove = presum - k ; 
           count += mpp[remove] ; 
          mpp[presum] += 1 ;

        }
        return count ;
    }
};
