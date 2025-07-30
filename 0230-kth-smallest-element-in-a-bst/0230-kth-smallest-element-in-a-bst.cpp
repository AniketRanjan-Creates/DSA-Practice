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
    int cnt  = 0;
    int result  = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;                
    }
private:
    void inorder(TreeNode* node, int k) {
        if(node==NULL) return;
        inorder(node->left, k);
        cnt++;
        if(cnt==k) {
            result = node->val;
            return;
        }
        inorder(node->right, k);
    }    
};