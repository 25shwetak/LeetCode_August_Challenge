/*

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
	    vector<int> B,C;
	    for(auto it = A.begin(); it != A.end(); it++){
		    if( *it % 2 == 0)
			    B.push_back(*it);
		    else
			    C.push_back(*it);
	    }
	    for(auto it = C.begin(); it != C.end(); it++){
		    B.push_back(*it);
	    }
        return B;
    }
};
