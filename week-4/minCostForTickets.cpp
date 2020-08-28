/*

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

1. a 1-day pass is sold for costs[0] dollars;
2. a 7-day pass is sold for costs[1] dollars;
3. a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

*/

class Solution {
   public:
   int mincostTickets(vector<int>& days, vector<int>& costs) {
      vector <int> dp(366);
      int j = 0;
      for(int i = 1; i < 366; i++){
         dp[i] = costs[0] + dp[i - 1];
         if(i - 7 >= 0){
            dp[i] = min(dp[i - 7] + costs[1], dp[i]);
         }
         if(i - 30 >= 0){
            dp[i] = min(dp[i - 30] + costs[2], dp[i]);
         }
         if(j < days.size() && days[j] == i){
            j++;
         }else
            dp[i] = min(dp[i], dp[i - 1]);
      }
      return dp[365];
   }
};
