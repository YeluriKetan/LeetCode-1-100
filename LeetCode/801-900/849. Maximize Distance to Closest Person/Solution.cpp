class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxGap = 0;
        int index = 0;
        int prev = -1;
        while (index < n) {
            if (seats[index]) {
                maxGap = index;
                prev = index;
                index++;
                break;
            } else {
                index++;
            }
        }
        while (index < n) {
            if (seats[index]) {
                maxGap = max(maxGap, (index - prev) / 2);
                prev = index;
            }
            index++;
        }
        maxGap = max(maxGap, n - prev - 1);
        return maxGap;
    }
};
