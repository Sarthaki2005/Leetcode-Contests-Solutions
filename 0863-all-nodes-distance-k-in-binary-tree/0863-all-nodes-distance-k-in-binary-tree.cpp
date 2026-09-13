/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left) {q.push(node->left);parent[node->left]=node;}
            if(node->right) {q.push(node->right);parent[node->right]=node;}

        }
        map<TreeNode*,int> visited;
        queue<TreeNode*> pq;
        pq.push(target);
        visited[target]=1;
        int dist=0;
        while(!pq.empty()){
            if(dist==k) break;
            int size=pq.size();
            while(size--){
            auto node=pq.front();
            pq.pop();
            if(parent[node]!=NULL && !visited[parent[node]]){
                pq.push(parent[node]);
                visited[parent[node]]=1;
            }
            if(node->left && !visited[node->left]){
                pq.push(node->left);
                visited[node->left]=1;
            }
            if(node->right && !visited[node->right]){
                pq.push(node->right);
                visited[node->right]=1;
            }
            }
dist++;
        }
        vector<int> ans;
        while(!pq.empty()){
            auto node=pq.front();
            pq.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};