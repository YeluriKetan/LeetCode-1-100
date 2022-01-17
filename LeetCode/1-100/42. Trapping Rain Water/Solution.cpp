class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> heightStack;
        heightStack.push(0);
        int totalWater = 0;
        int prevFloor = 0;
        int leftWall;
        for (int i = 1; i < n; ++i) {
            prevFloor = 0;
            while (!heightStack.empty() && height[heightStack.top()] <= height[i]) {
                leftWall = heightStack.top();
                heightStack.pop();
                totalWater += (height[leftWall] - prevFloor) * (i - leftWall - 1);
                prevFloor = height[leftWall];
            }
            if (!heightStack.empty()) {
                totalWater += (height[i] - prevFloor) * (i - heightStack.top() - 1);
            }
            heightStack.push(i);
        }
        return totalWater;
    }
};
