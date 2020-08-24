/*

Find the sum of all left leaves in a given binary tree.

*/

class Solution {
public:
    bool isLeaf(TreeNode *node) 
    { 
        if (node == NULL) 
            return false; 
        if (node->left == NULL && node->right == NULL) 
            return true; 
        return false; 
    } 
    int sumOfLeftLeaves(TreeNode *root) 
    { 
        int res = 0; 
        if (root != NULL) 
        { 
            if (isLeaf(root->left)) 
                res += root->left->val; 
            else 
                res += sumOfLeftLeaves(root->left); 
            res += sumOfLeftLeaves(root->right); 
        } 
        return res; 
    } 
};
