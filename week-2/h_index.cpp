/*

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int result = 0;
        for(int i = citations.size()-1; i>=0; i--){
            int cnt = citations.size()-i;
            if(citations[i]>=cnt){
                result = cnt;
            }
            else
                break;
        }
        return result;
    }
};
