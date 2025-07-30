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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if (root->val>key) {
            root->left=deleteNode(root->left, key);
        }else if (root->val<key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;

            TreeNode* minNode = FindingMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }    
    TreeNode* FindingMin(TreeNode* node) {
        while(node->left) {
            node=node->left;
        }
        return node;
    }
};