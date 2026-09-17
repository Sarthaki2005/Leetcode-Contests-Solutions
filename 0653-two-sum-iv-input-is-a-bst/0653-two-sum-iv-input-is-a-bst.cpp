/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class BSTIterator{
        stack<TreeNode*> st1,st2;
        public:

        BSTIterator(TreeNode* node){
            TreeNode* temp=node;
            while(temp!=NULL){
                st1.push(temp);
                temp=temp->left;
            }

            temp=node;
            while(temp!=NULL){
                st2.push(temp);
                 temp=temp->right;
            }
        }
        int next(){
            TreeNode* node=st1.top();
            st1.pop();
            TreeNode* temp=node->right;
            while(temp!=NULL){
st1.push(temp);
temp=temp->left;
            }
            return node->val;
        }

        int before(){
            TreeNode* node=st2.top();
            st2.pop();
            TreeNode* temp=node->left;
            while(temp!=NULL){
                st2.push(temp);
                temp=temp->right;
            }
            return node->val;
        }
        bool f(int k) 
        { 
            while(!st1.empty() && !st2.empty()){
                TreeNode* left=st1.top();
                TreeNode* right=st2.top();
                if(left==right) break;
            int sum=left->val+right->val;
            if(sum>k){
                before();
            }
            else if(sum<k){
                next();

            }
            else return true;
         }
         return false;
         }

    };
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bst(root);
     return bst.f(k);

    }
};