/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num==0)
            return false;
        double i = log(num) / log(4);
        return i == trunc(i);
    }
};
