Merge Two BST's ( med ) // solve after iterator bst problem for better understanding.
Platform : GFG 
  
https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


class Solution {
public:

    stack<Node*> st1, st2;          // Two stacks for two BSTs

    // Push complete left path
    void pushAllLeft(Node* root, stack<Node*>& st)
    {
        while(root != NULL)
        {
            st.push(root);          // Push node into stack
            root = root->left;      // Move to left child
        }
    }



    vector<int> merge(Node* root1, Node* root2)
    {
        vector<int> ans;            // Store final merged answer

        pushAllLeft(root1, st1);    // Initialize iterator of BST1
        pushAllLeft(root2, st2);    // Initialize iterator of BST2
        
while(!st1.empty() || !st2.empty())
{
    // BST1 is empty, so take node from BST2
    if(st1.empty())
    {
        Node* temp = st2.top();
        st2.pop();

        ans.push_back(temp->data);
        pushAllLeft(temp->right, st2);
    }

    // BST2 is empty, so take node from BST1
    else if(st2.empty())
    {
        Node* temp = st1.top();
        st1.pop();

        ans.push_back(temp->data);
        pushAllLeft(temp->right, st1);
    }

    // Both stacks have nodes
    else
    {
        // BST1 has smaller value
        if(st1.top()->data <= st2.top()->data)
        {
            Node* temp = st1.top();
            st1.pop();

            ans.push_back(temp->data);
            pushAllLeft(temp->right, st1);
        }

        // BST2 has smaller value
        else
        {
            Node* temp = st2.top();
            st2.pop();

            ans.push_back(temp->data);
            pushAllLeft(temp->right, st2);
        }
    }
}
        return ans;     // Return merged sorted array
    }
};
