
https://www.geeksforgeeks.org/problems/predecessor-and-successor/1?utm_source=chatgpt.com
class Solution {
public:

    Node* predecessor(Node* root, int key) {

        Node* ans = NULL;

        while (root != NULL) {

            if (root->data < key) {
                ans = root;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return ans;
    }

    Node* successor(Node* root, int key) {

        Node* ans = NULL;

        while (root != NULL) {

            if (root->data > key) {
                ans = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return ans;
    }

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = predecessor(root, key);
        Node* suc = successor(root, key);

        return {pre, suc};
    }
};
