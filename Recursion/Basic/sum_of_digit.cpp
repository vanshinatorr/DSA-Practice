https://www.geeksforgeeks.org/problems/sum-of-digits1742/1


// que solve in crt class ; level easy


class Solution {
  public:

    int sumnum(int n) {

        // Base case
        if (n == 0) {
            return 0;
        }

        int digit = n % 10;

        // Recursive call
        return digit + sumnum(n / 10);
    }

    int sumOfDigits(int n) {
        return sumnum(n);
    }
};
