#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
       int data ;
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
   if(Tree[idx]==-1) return nullptr;
   Node* root = new Node(Tree[idx]);
   root->left = buildTree(Tree);
   root->right = buildTree(Tree);
   return root;

}
void levelOrder(Node* root){
     if(root==nullptr) return ;

     queue<Node*>q;
     q.push(root);
     q.push(NULL);
     while (!q.empty())
     {
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){

            if(!q.empty()){
                 cout<<endl;
                 q.push(NULL);
                 continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left!=nullptr){
                q.push(curr->left);
        }
        if(curr->right !=nullptr){
             q.push(curr->right);
        }
     } 
}
int main(){
     
    vector<int> Tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(Tree);
    levelOrder(root);
}