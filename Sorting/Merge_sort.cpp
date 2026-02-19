/*
==============================
        MERGE SORT
https://www.naukri.com/code360/problems/merge-sort_920442?leftPanelTabValue=SUBMISSION
on code360
==============================

Approach:
- Uses Divide and Conquer.
- Recursively divide array into two halves.
- Sort both halves.
- Merge the sorted halves using a temporary array.

Base Case:
- If low >= high → subarray size is 1 → already sorted.

Time Complexity:
- O(N log N)
  log N levels of recursion
  N work at each level during merge

Space Complexity:
- O(N) auxiliary space (temporary array used in merge)

Stable Sorting Algorithm: YES
In-Place: NO (uses extra space)

*/

void merge(vector<int> &arr, int low, int mid, int high){

    int left = low; 
    int right = mid + 1; 
    vector<int> temp; 

    // Merge two sorted halves
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]); 
            left++; 
        }
        else{
            temp.push_back(arr[right]); 
            right++; 
        }
    }

    // Remaining elements from left half
    while(left <= mid){
        temp.push_back(arr[left]); 
        left++;
    }

    // Remaining elements from right half
    while(right <= high){
        temp.push_back(arr[right]); 
        right++; 
    }

    // Copy sorted elements back to original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low]; 
    }
}

void ms(vector<int> &arr, int low, int high){

    if(low >= high) return;  // Base case

    int mid = (low + high) / 2; 

    ms(arr, low, mid);       // Sort left half
    ms(arr, mid+1, high);    // Sort right half
    merge(arr, low, mid, high); // Merge both halves
}

void mergeSort(vector<int> &arr, int n){
    ms(arr, 0, n-1); 
}
