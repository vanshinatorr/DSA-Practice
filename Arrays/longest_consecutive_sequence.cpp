// Longest Consecutive Sequence
// Approach: HashSet
// Time: O(n)




1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        
5        int n = nums.size() ; 
6        if ( n == 0 )
7        return  0 ; 
8        int longest  = 1 ; 
9        unordered_set<int>st; 
10
11        for (int i=0;i< n; i++) {
12            st.insert(nums[i]) ; 
13        }
14        for(auto it:st ){
15            if(st.find(it-1 ) == st.end()){
16                int cnt = 1 ; 
17                int x = it ; 
18
19                while(st.find(x+1) != st.end()){
20                        x = x+ 1  ; 
21                        cnt = cnt+ 1 ; 
22                }
23            longest = max(longest,cnt ) ; 
24            }
25        }
26          return longest ;
27    }
28  
29};
30
31
32
33
34// Ordered set bhi use ho sakta tha, lekin uski time complexity O(n log n) hoti hai.
35// Question me O(n) required hai, isliye fast lookup ke liye unordered_set use kiya.
36// Hume sorting nahi, sirf x-1 aur x+1 ka existence check karna hai.
