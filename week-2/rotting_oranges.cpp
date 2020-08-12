/*

In a given grid, each cell can have one of three values:

- the value 0 representing an empty cell;
- the value 1 representing a fresh orange;
- the value 2 representing a rotten orange.
- Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int day = 0, fresh = 0;
        queue<array<int, 2>> q;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    ++fresh;
                else if (grid[i][j] == 2)
                    q.push({i, j});
        vector<array<int, 2>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        while (!q.empty()) {
            int n = q.size();
            bool rotten = false;
            for (int i = 0; i < n; ++i) {
                auto x = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int i = x[0] + dir[0];
                    int j = x[1] + dir[1];
                    if (0 <= i && i < grid.size() && 0 <= j && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        --fresh;
                        rotten = true;
                    }
                }
            }
            if (rotten)
                ++day;
        }
        return fresh ? -1 : day;
    }
};
