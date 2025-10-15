
/*There are three solutions to this problem.

Iterative solution using stack: O(n) time and O(n) space;
Recursive solution: O(n) time and O(n) space (function call stack);
Morris traversal: O(n) time and O(1) space.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                // find predecedor
                TreeNode* IP = curr->left;
                while(IP->right !=NULL && IP->right!=curr){
                    IP = IP->right;
                }
                if(IP->right==NULL){
                    IP->right = curr;  // create thread
                    curr=curr->left;
                }else{
                    IP->right=nullptr; // delete thread
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }


        }
        return ans;
    }
};


🧠 So, Summary:
Concept	                     Inorder                               	Preorder
Visit Timing	          After left subtree done	           Before left subtree start 
Thread তৈরি করার সময়	   Visit করা হয় না                       Visit করা হয়
Thread ভাঙার সময়	       Visit করা হয়	                        Visit করা হয় না
Order	                   Left → Root → Right	               Root → Left → Right
                     (root-left not available push root)       (root-left) available push root

*/