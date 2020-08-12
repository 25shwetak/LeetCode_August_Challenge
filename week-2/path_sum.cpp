/*

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

*/

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
    int count = 0;
    int printKPathUtil(TreeNode *root, vector<int>& path, int k) 
    { 
        if (!root) 
            return count;
        path.push_back(root->val); 
        printKPathUtil(root->left, path, k);
        printKPathUtil(root->right, path, k); 
        int f = 0; 
        for (int j=path.size()-1; j>=0; j--) 
        {    
            f += path[j]; 
  
            if (f == k) 
                count++; 
        }  
        path.pop_back(); 
        return count;
    } 
    int pathSum(TreeNode *root, int k) 
    { 
        vector<int> path; 
        int count = printKPathUtil(root, path, k);
        return count;
    } 
};
