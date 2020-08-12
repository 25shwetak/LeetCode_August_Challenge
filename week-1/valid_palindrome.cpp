/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

*/

class Solution {
public:
    	bool isPalindrome(string s) {
        	if (s.length()==0)
            return true;
        for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] + 32;
        }
        string str = "";
        for(int i=0;i<s.length();i++){
            int x = int(s.at(i));
            if((x>96 && x<123) || (x>64 && x<91) || (x>=48 && x<=57)){
                str += s.at(i);
            }
        }
        string str1 = str;
        reverse(str.begin(), str.end());
        if(str == str1)
            return true;
        else
            return false;
    }
};
