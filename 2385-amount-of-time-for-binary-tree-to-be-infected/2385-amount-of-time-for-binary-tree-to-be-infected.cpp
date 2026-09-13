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
    int amountOfTime(TreeNode* root, int start) {
        //mark the parents
        map<TreeNode*,TreeNode*> parent;
        TreeNode* st;
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            auto node=q.front();
            if(node->val==start) st=node;
            q.pop();
            if(node->left) {q.push(node->left); parent[node->left]=node;}
            if(node->right) {q.push(node->right); parent[node->right]=node;}

            
        }
        int time=0;
        map<TreeNode*,int> visited;
        queue<TreeNode*> pq;
        pq.push(st);
        visited[st]=1;
        while(!pq.empty()){
             int size=pq.size();
             while(size--){
                auto node=pq.front();
                pq.pop();
                if(parent[node]!=NULL && !visited[parent[node]]) {pq.push(parent[node]); visited[parent[node]]=1;}
                if(node->left && !visited[node->left]) {pq.push(node->left); visited[node->left]=1;}
                if(node->right && !visited[node->right]) {pq.push(node->right); visited[node->right]=1;}


             }
             time++;
        }
        return time-1;
    }
};