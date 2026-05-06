/*
    Problem: Remove Duplicates from Sorted Array
    Platform: LeetCode 26

    ====================================================

    🔥 IMPORTANT REVISION NOTE

    Is question ko generally 2 ways me solve kiya jata hai:

    ----------------------------------------------------
    1️⃣ Sorted Array -> Two Pointer Approach
    2️⃣ Unsorted Array -> HashSet Approach
    ----------------------------------------------------

    ✅ Maine GitHub pe jo already push kiya hai
    wo SORTED ARRAY wala approach hai.

    Kyuki is question me array sorted hota hai.

    ====================================================

    ✅ WHY TWO POINTER WORKS HERE?

    Example:

    [1,1,2,2,3,3]

    Yaha duplicates paas-paas (adjacent) hain.

    Since sorted array me same elements ek saath aate hain,
    hum bas previous unique element se compare kar sakte hain.

    Example:

    nums[i] != nums[j]

    Agar different hua:
    => new unique element mila

    Isliye:
    - HashSet ki zarurat nahi
    - Extra space nahi lagta
    - In-place solve ho jata hai

    ====================================================

    ❌ AGAR ARRAY SORTED NA HOTA

    Example:

    [4,2,1,2,4,5]

    Yaha duplicates random positions par hain.

    To adjacent compare fail ho jayega.

    Example:

    4 != 2
    2 != 1
    1 != 2

    Sab unique lag rahe 😂

    Isliye unsorted array me use karte:

    unordered_set<int> seen;

    Taaki yaad rahe kaunsa element already aa chuka hai.

    ====================================================

    🧠 EASY MEMORY TRICK

    Agar duplicates paas-paas hain
    => Two Pointer

    Agar duplicates random jagah hain
    => Hashing / Set

    ====================================================

    Problem Statement:

    Given a sorted array nums,
    remove duplicates in-place such that each
    unique element appears only once.

    Return the number of unique elements.

    Example:
    Input:  [1,1,2]
    Output: 2

    nums => [1,2,_]

    ====================================================

    APPROACH (Two Pointer Technique)

    We use:

    i = write pointer
    -> last unique element ka index

    j = read pointer
    -> pura array traverse karega

    Jab bhi nums[j] != nums[i]

    => new unique element mila

    Then:
    - us unique element ko next position pe store karo
    - i ko aage badhao

    ====================================================

    DRY RUN

    nums = [1,1,2,2,3]

    i = 0

    j = 1

    nums[1] == nums[0]
    duplicate
    skip

    --------------------------------

    j = 2

    nums[2] != nums[0]

    unique found

    nums[i+1] = nums[2]

    Array becomes:

    [1,2,2,2,3]

    i++

    Continue...

    Final:

    [1,2,3,_,_]

    ====================================================

    Time Complexity:
    O(N)

    Space Complexity:
    O(1)

    ====================================================

    COMMON MISTAKES

    1. nums[i] instead of nums[i+1]

    2. Wrong pointer increment

    3. Extra i++ inside loop

    4. Forgetting array is sorted

    ====================================================
*/

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        // Edge case
        if(n == 0) return 0;

        // i = write pointer
        int i = 0;

        // j = read pointer
        for(int j = 1; j < n; j++) {

            // New unique element found
            if(nums[i] != nums[j]) {

                // Store new unique element
                nums[i + 1] = nums[j];

                // Move write pointer
                i++;
            }
        }

        // Total unique elements
        return i + 1;
    }
};
