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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i = 0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }  
        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int pstart, int pend, map<int, int>& inMap){
        if(instart>inend || pstart>pend) return NULL;
        TreeNode* root = new TreeNode(postorder[pend]);
        int rootin = inMap[root->val];
        int numsleft = rootin - instart;
        root->left = buildTree(inorder, instart, rootin-1, postorder, pstart, pstart+numsleft-1, inMap);
        root->right = buildTree(inorder, rootin+1, inend, postorder, pstart+numsleft, pend-1, inMap);
        return root;
    }
};