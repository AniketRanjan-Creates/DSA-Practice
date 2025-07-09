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
private:
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent_track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parent_track[node->right]=node;
                q.push(node->right);
            }

        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparent(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qu;
        visited[target] = true;
        int level = 0;
        qu.push(target);
        while(!qu.empty()){
            int size = qu.size();
            if(level==k) break;
            else level++;

            
            for(int i =0; i<size; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if(node->left && !visited[node->left]) {
                    qu.push(node->left);
                    visited[node->left] = true;
                }  
                if(node->right && !visited[node->right]) {
                    qu.push(node->right);
                    visited[node->right] = true;
                } 
                if(parent_track[node] && !visited[parent_track[node]]) {
                    qu.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                } 
            }
        }
        vector<int> result;
        while(!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            result.push_back(node->val);
            
        }
        return result;

    }
};