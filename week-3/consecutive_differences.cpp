/*

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
      vector <int> dp[N + 1];
      for(int i = 1; i <= 9; i++){
         dp[1].push_back(i);
      }
      for(int i = 1; i < N; i++){
         set <int> visited;
         for(int j = 0; j < dp[i].size(); j++){
            int x = dp[i][j];
            int lastNum = x % 10;
            int digit = lastNum + K;
            if(digit >= 0 && digit <= 9 && !visited.count(x * 10 + digit)){
               dp[i + 1].push_back(x * 10 + digit);
               visited.insert(x * 10 + digit);
            }
            digit = lastNum - K;
            if(digit >= 0 && digit <= 9 && !visited.count(x * 10 + digit)){
               dp[i + 1].push_back(x * 10 + digit);
               visited.insert(x * 10 + digit);
            }
         }
      }
      if(N == 1){
         dp[N].push_back(0);
      }
      return dp[N];
   }
};
