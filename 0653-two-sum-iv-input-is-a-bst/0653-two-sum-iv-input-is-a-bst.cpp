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
    bool findTarget(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        int n = result.size();
        int i = 0; int j = n-1;
        while (i<j) {
            if(result[i]+result[j]>k) j--;
            else if(result[i]+result[j]<k) i++;
            else if(result[i]+result[j]==k) return true;
            
        }
        return false;
    }    
private:        

    void inorder(TreeNode* root, vector<int>& result) {
        if (root==NULL) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};