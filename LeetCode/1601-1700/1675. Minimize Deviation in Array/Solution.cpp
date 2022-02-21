class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minNum = INT_MAX;
        priority_queue<int> pq;
        for (auto &curr: nums) {
            if (curr % 2 == 1) {
                curr *= 2;
            }
            minNum = min(minNum, curr);
            pq.push(curr);
        }
        int minDev = pq.top() - minNum;
        int temp, prev = -1;
        while ((temp = pq.top()) % 2 == 0) {
            pq.pop();
            minDev = min(minDev, temp - minNum);
            temp /= 2;
            minNum = min(minNum, temp);
            pq.push(temp);
        }
        return min(minDev, pq.top() - minNum);
    }
};