/*

Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row = 0, col = 0, index = 41;
        while(index > 40) {
            row = rand7();
            col = rand7();
            index = col + (row - 1) * 7;
        }
        return 1 + (index - 1) % 10;
    }
};
