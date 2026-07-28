https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1?utm_source=chatgpt.com



/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
    
        int ans = -1  ; 
        
        while ( root != nullptr){
        
            if ( root -> data > k -> data ){
                ans = root -> data  ; 
                root = root -> left ;  
            }
            
            else {
               root = root -> right ;  
            }
        }
        
        return ans; 
    }
};
