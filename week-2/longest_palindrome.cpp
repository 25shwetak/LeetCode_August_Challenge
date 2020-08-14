/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

*/

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> mp;
      for (auto i : s)
         mp[i]++;
      int ma = 0, c = 0, ans = 0;
      for (auto i : mp) {
         if ((i.second) % 2 == 1)
            ma++;
         c += i.second;
      }
      if (ma > 0)
         ma--;
      ans = c - ma;
      return ans;
    }
};
