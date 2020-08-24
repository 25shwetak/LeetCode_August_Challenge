/*

Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

1. An integer point is a point that has integer coordinates. 
2. A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
3. ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
4. length and width of each rectangle does not exceed 2000.
5. 1 <= rects.length <= 100
6. pick return a point as an array of integer coordinates [p_x, p_y]
7. pick is called at most 10000 times.

*/

class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> rect) {
        rects = rect;
        int totalArea=0;
        for (auto r: rects) {
            totalArea+=area(r);
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(), v.end(), rnd) - v.begin();
        auto r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};
