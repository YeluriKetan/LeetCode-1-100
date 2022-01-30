class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> monoStack;
        int maxArea = 0;
        int pivot;
        int area;
        for (int i = 0; i < n; ++i) {
            if (monoStack.empty() || heights[monoStack.top()] <= heights[i]) {
                monoStack.push(i);
            } else {
                while (!monoStack.empty() && heights[monoStack.top()] > heights[i]) {
                    pivot = monoStack.top();
                    monoStack.pop();
                    area = heights[pivot] * (monoStack.empty() ? i : i - monoStack.top() - 1);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
                monoStack.push(i);
            }
        }
        while (!monoStack.empty()) {
            pivot = monoStack.top();
            monoStack.pop();
            area = heights[pivot] * (monoStack.empty() ? n : n - monoStack.top() - 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};