/* # Find Nth Root of a Number (Binary Search)


https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=SUBMISSION  
solved on code360



int NthRoot(int n, int m) {

    int low = 1;            // nth root of positive m can never be 0
    int high = m;

    while (low <= high) {

        int mid = low + (high - low) / 2;
        long long val = 1;

        // Calculate mid^n safely
        for (int i = 0; i < n; i++) {
            val *= mid;

            // If value exceeds m, no need to continue
            // Example: m=27, mid=4 → 4^3=64 (>27)
            if (val > m) break;
        }

        if (val == m) {
            return mid;         // exact nth root found
        }
        else if (val > m) {
            high = mid - 1;     // search left
        }
        else {
            low = mid + 1;      // search right
        }
    }

    return -1;  // no integer nth root exists
}
