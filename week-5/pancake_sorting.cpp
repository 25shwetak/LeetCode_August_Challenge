/*

Given an array of integers A, We need to sort the array performing a series of pancake flips.

In one pancake flip we do the following steps:

1. Choose an integer k where 0 <= k < A.length.
2. Reverse the sub-array A[0...k].

*/

class Solution {
public:
    vector<int> B;
    bool isSorted(vector<int> &A){
        return A==B;
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        B = A;
        sort(B.begin(), B.end());
        vector<int> res;
        int i = A.size()-1, mx;
        while(!isSorted(A) && i>0){
            mx = max_element(A.begin(), A.begin()+i+1)-A.begin();
            if(mx!=i){
                reverse(A.begin(), A.begin()+mx+1);
                res.push_back(mx+1);
                reverse(A.begin(), A.begin()+i+1);
                res.push_back(i+1);
            }
            i--;
        }
        return res;
    }
};
