/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int val = abs(nums[i]) - 1;
            if(nums[val] > 0)
                nums[val] = -nums[val];
            else
                res.push_back(val+1);
        }
        return res;
    }
};
