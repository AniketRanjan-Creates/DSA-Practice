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
        if(root==NULL) return 0;
        int count = 0;
        preorder(root, count);
        return count;
               
    }
private: 
    void preorder(TreeNode* node, int& count) {
        if(node==nullptr) return;
        count++;
        preorder(node->left, count);
        preorder(node->right, count);
    }
};