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
    int countNodes(TreeNode* root) {
         vector<int> result;
        preorder(root, result);
        int count = 0;
        for(int i = 0; i<result.size(); i++) {
            count++;
        }
        return count;
               
    }
private: 
    void preorder(TreeNode* node, vector<int>&result) {
        if(node==nullptr) return;
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }
};