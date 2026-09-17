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
TreeNode* build(vector<int> &inorder,int inStart,int inEnd,vector<int> &preorder,int preStart,int preEnd,map<int,int> &mp){
    if(inStart>inEnd || preStart>preEnd) return NULL;
    TreeNode* root=new TreeNode(preorder[preStart]);
   int inroot=mp[root->val];
   int numL=inroot-inStart;
   root->left=build(inorder,inStart,inroot-1,preorder,preStart+1,preStart+numL,mp);
   root->right=build(inorder,inroot+1,inEnd,preorder,preStart+numL+1,preEnd,mp);
   return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
         sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
       
        TreeNode* root=build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
        return root;
    }
};