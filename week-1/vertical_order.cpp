/*

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

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
    void traverse(TreeNode* r, int x, int y, unordered_map<int, unordered_map<int, set<int>>> &m) {
        if (r != nullptr) {
            m[x][y].insert(r->val);
            traverse(r->left, x - 1, y + 1, m);
            traverse(r->right, x + 1, y + 1, m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* r, vector<vector<int>> res = {}) {
        unordered_map<int, unordered_map<int, set<int>>> m;
        traverse(r, 0, 0, m);
        for (int x = -999; x < 1000; ++x) {
            if (m.find(x) != end(m)) {
            res.push_back(vector<int>());
            for (int y = 0; y < 1000; ++y)
                if (m[x].find(y) != end(m[x]))
                res.back().insert(end(res.back()), begin(m[x][y]), end(m[x][y]));
            }
        }
        return res;
    }
};
