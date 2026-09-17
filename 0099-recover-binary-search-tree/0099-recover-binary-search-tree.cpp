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
void f(TreeNode* root,vector<int> &arr,int &ptr){
  if(root!=NULL) { 
    f(root->left,arr,ptr);
    if(root->val!=arr[ptr]){
        root->val=arr[ptr];
        
    }
    ptr++;
    f(root->right,arr,ptr); }
}

    void recoverTree(TreeNode* root) {
        //iterative inorder
        TreeNode* curr=root;
        vector<int> inorder;
        stack<TreeNode*> st;
       while(true){
        if(curr==NULL){
            if(st.empty()) break;
            TreeNode* temp=st.top();
            st.pop();
            inorder.push_back(temp->val);
           curr=temp->right;
        }else{
            st.push(curr);
            curr=curr->left;
        }
       }
       sort(inorder.begin(),inorder.end());
       int ptr=0;
        f(root,inorder,ptr);      

    }
};