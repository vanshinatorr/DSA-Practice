https://www.naukri.com/code360/problems/next-smaller-element_1112581?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM

#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    
  vector<int> ans(n); 
  stack<int> st ; 
    for ( int i = n-1 ; i>= 0; i--){

while ( !st.empty() && st.top() >= arr[i]){
    st.pop(); 
}


if (st.empty()){
    ans[i] = -1 ; 
}

else {
ans[i] = st.top() ; 
}
st.push(arr[i]) ; 
        
    }
    return ans  ; 

}
