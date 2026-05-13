https://www.geeksforgeeks.org/problems/reverse-an-array/1?utm_source=chatgpt.com

// solve in class 

class Solution {
public:

    void reverse(int first, int last, vector<int> &arr) {

        // Base case
        if (first >= last) {
            return;
        }

        // Swap elements
        swap(arr[first], arr[last]);

        // Recursive call
        reverse(first + 1, last - 1, arr);
    }






    void reverseArray(vector<int> &arr) {

        int n = arr.size();

        reverse(0, n - 1, arr);
    }
};
