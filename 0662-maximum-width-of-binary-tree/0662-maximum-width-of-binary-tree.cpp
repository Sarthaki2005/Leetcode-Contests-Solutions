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
using ll=long long;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        ll max_len=0;
        q.push({root,0});
        while(!q.empty()){
            ll fi,li;
            int size=q.size();
          ll min=q.front().second;
          for(int i=0;i<size;i++){
            auto it=q.front();
            TreeNode* node=it.first;
            q.pop();
            ll currId=it.second-min;
            if(i==0) fi=currId;
            if(i==size-1) li=currId;
            if(node->left) q.push({node->left,currId*2+1});
            if(node->right) q.push({node->right,currId*2+2});
            
          }
            max_len=max(max_len,li-fi+1);
        }
    return max_len;
    }
};