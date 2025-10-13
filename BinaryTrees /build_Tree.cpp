#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int _data){
       data = _data;
       left=right=nullptr;
    }

};

static int idx=-1;
Node* buildTree(vector<int> Tree){
    idx++;
    if(Tree[idx]==-1){
        return nullptr;
    }
    Node* root = new Node(Tree[idx]);
    root->left= buildTree(Tree);
    root->right=buildTree(Tree);
    return root;

}
void PreOrder(Node* root){
   if(root==nullptr){
      return;
   }
   cout<<root->data<<" ";
   PreOrder(root->left);
   PreOrder(root->right);
}

void InOrder(Node* root){
     if(root==nullptr){
        return;
     }
     InOrder(root->left);
     cout<<root->data<<" ";
     InOrder(root->right);

}
void PostOrder(Node* root){
    if(root==nullptr){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> Tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(Tree);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    return 0;
}