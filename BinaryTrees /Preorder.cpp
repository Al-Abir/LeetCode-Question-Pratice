
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        if(!root) return nodes;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            nodes.push_back(node->val); // Root visit

            if(node->right) st.push(node->right); // Right push first
            if(node->left) st.push(node->left);   // Left push next
        }

        return nodes;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }

private:
    void preorder(TreeNode* root, vector<int>& nodes) {
        if(!root) return;

        nodes.push_back(root->val);       // Root
        preorder(root->left, nodes);      // Left
        preorder(root->right, nodes);     // Right
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while(root) {
            if(root->left) {
                TreeNode* pre = root->left;
                while(pre->right && pre->right != root) {
                    pre = pre->right;
                }

                if(!pre->right) {
                    nodes.push_back(root->val); // Root visit before threading
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                nodes.push_back(root->val); // Root visit
                root = root->right;
            }
        }
        return nodes;
    }
};
Preorder: Root → Left → Right

Morris Preorder: Root visit threading করার আগে করি (inorder এর মতো পরে নয়)।

Iterative stack: Right push → Left push, যাতে left আগে process হয়।

*/