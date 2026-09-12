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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;  //{Node,{vertical,level}}
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int vertical=it.second.first;
            int level=it.second.second;
            mp[vertical][level].insert(node->val);
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});

        }
        vector<vector<int>> ans;
        for(auto &p:mp){
            vector<int> local;
            for(auto &row:p.second){
local.insert(local.end(),row.second.begin(),row.second.end());
            }
ans.push_back(local);
        }
        return ans;
    }
};