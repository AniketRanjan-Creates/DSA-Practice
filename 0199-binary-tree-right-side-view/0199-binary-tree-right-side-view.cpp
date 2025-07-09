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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        map<int, int> mpp;
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.second;
            int line  = it.first;
            if(mpp.find(line)==mpp.end()) mpp[line] = node->val;
            if(mpp.find(line)!=mpp.end()) mpp[line] = node->val;

            if(node->left!=NULL) {
                q.push({line+1, node->left});
            }
            if(node->right!=NULL) {
                q.push({line+1, node->right});
            }
        }
        for(auto it : mpp) {
            result.push_back(it.second);
        }
        return result;
        
    }
};