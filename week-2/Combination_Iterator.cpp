/*

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.

*/

class CombinationIterator {
private:
    vector<string> dic;
    int idx = 0;
    void buildIterator(int begin, string &cur, int combinationLength, string &characters) {
        if (cur.length() == combinationLength) {
            dic.push_back(cur);
            return;
        }
        for (int i = begin + 1; i < characters.length(); i++) {
            cur += characters[i];
            buildIterator(i, cur, combinationLength, characters);
            cur.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        for (int i = 0; i < characters.size(); i++) {
            string cur;
            cur += characters[i];
            buildIterator(i, cur, combinationLength, characters);
        }
    }
    
    string next() {
        return dic[idx++];
    }
    
    bool hasNext() {
        return idx < dic.size();
    }

};
