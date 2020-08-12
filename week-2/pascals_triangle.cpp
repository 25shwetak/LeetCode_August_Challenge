/*

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

*/

class Solution {
public:
    vector<int> getRow(int Index) {
        int rowIndex = Index+1;
        vector<vector<int>> result;
        if(rowIndex <= 0 )
            return result[0];
        vector<int> pre;
        pre.push_back(1);
        result.push_back(pre);
        
        for(int i=2; i <= rowIndex ; i++){
            vector<int> cur;
            
            cur.push_back(1);
            for(int j=0;j<pre.size()-1;j++){
                cur.push_back(pre[j] + pre[j+1]);
            }
            cur.push_back(1);
            
            result.push_back(cur);
            pre = cur;
        }
        return result[Index];
    }
};
