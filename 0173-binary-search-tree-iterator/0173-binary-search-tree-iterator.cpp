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
class BSTIterator {
private: 
    vector<int> result;
    int index;

    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        inorder(root);
        
        
    }
    
    int next() {
        int val = result[index];
        index++;
        return val;
        
    }
    
    bool hasNext() {
        return index<result.size();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */