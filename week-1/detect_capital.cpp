/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                count++;
            }
        }
        if(count == word.length() || count == 0)
            return true;
        else if(count == 1){
            if(word[0]>='A' && word[0]<='Z')
                return true;
        }
        return false;    
    }
};
