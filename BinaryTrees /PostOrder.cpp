/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }

private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;

        postorder(root->left, nodes);   // Left
        postorder(root->right, nodes);  // Right
        nodes.push_back(root->val);     // Root
    }
};
2️⃣ Iterative Postorder using two stacks

Idea:

Postorder = Left → Right → Root

Reverse preorder trick: Preorder = Root → Left → Right

যদি আমরা Root → Right → Left traverse করি এবং reverse করি, postorder পাই।

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        if (!root) return nodes;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top(); st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            nodes.push_back(st2.top()->val);
            st2.pop();
        }

        return nodes;
    }
};

3️⃣ Iterative Postorder using one stack

এটা একটু tricky। Steps:

Stack এ root push করো।

Current node = stack top।

Check করো: left বা right visit হয়নি → push করো।

Left/Right visit হলে pop করে result push করো।
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        if(!root) return nodes;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();

            // Going down
            if(!prev || prev->left == curr || prev->right == curr) {
                if(curr->left) st.push(curr->left);
                else if(curr->right) st.push(curr->right);
            }
            // Going up from left
            else if(curr->left == prev) {
                if(curr->right) st.push(curr->right);
            }
            // Going up from right
            else {
                nodes.push_back(curr->val);
                st.pop();
            }

            prev = curr;
        }

        return nodes;
    }
};
*/