class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> rec;
        int ar = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (rec.size() && heights[i] < heights[rec.top()]) {
                int h = heights[rec.top()];
                rec.pop();
                int w = rec.size() > 0 ? i - rec.top() - 1 : i;

                ar = std::max(ar, h * w);
            }
            rec.push(i);
        }

        while (rec.size()>0) {
            int h = heights[rec.top()];
            rec.pop();
            int w = rec.size() > 0 ? heights.size() - rec.top() - 1 : heights.size();

            ar = std::max(ar, h * w);
        }

        return ar;
    }
};
