
/*

medium - hard 
apna college code and tree in ruf 

https://leetcode.com/problems/palindrome-partitioning/submissions/2008850506/?utm_source=chatgpt.com

    Problem:
    Given a string s, partition s such that every substring
    of the partition is a palindrome.

    Return all possible palindrome partitionings.

    Example:
    Input:  "aab"

    Output:
    [
      ["a","a","b"],
      ["aa","b"]
    ]
*/


class Solution {
public:


    bool isPalin(string s) {

        string s2 = s;

        reverse(s2.begin(), s2.end());

        return s == s2;
    }


    /*
        ----------------------------------------------------
        Function: getAllParts
        ----------------------------------------------------

        Backtracking Function

        Parameters:
        - s       -> remaining string
        - ans     -> current partition
        - finals  -> stores all valid partitions

        Flow:
        1. Try every possible prefix
        2. If prefix is palindrome:
              - choose
              - recurse on remaining string
              - backtrack

        Example:
        "aab"

        Choices:
        "a"  -> recurse on "ab"
        "aa" -> recurse on "b"

    */

    void getAllParts(string s,
                     vector<string> &ans,
                     vector<vector<string>> &finals) {

        // Base Condition
        // Entire string consumed

        if (s.size() == 0) {

            finals.push_back(ans);
            return;
        }


        // Generate all prefixes

        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);


            // Process only palindrome prefixes

            if (isPalin(part)) {

                // Choose

                ans.push_back(part);


                // Explore remaining string

                getAllParts(s.substr(i + 1),
                            ans,
                            finals);


                // Backtrack

                ans.pop_back();
            }
        }
    }



    /*
        ----------------------------------------------------
        Main Function
        ----------------------------------------------------
    */

    vector<vector<string>> partition(string s) {

        vector<vector<string>> finals;

        vector<string> ans;

        getAllParts(s, ans, finals);

        return finals;
    }
};


/*
    ----------------------------------------------------
    Time Complexity:
    ----------------------------------------------------

    Exponential
    Approximately O(2^n * n)

    Because:
    - We generate multiple partitions
    - Palindrome checking also costs time


    ----------------------------------------------------
    Space Complexity:
    ----------------------------------------------------

    O(n)

    Recursion stack + current partition


    ----------------------------------------------------
    Core Backtracking Pattern:
    ----------------------------------------------------

    choose
    recurse
    backtrack

    i.e.

    push_back()
    recursive_call()
    pop_back()

*/
