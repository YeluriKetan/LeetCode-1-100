class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minInd = 0;
        int maxNeg = 0;
        int currTotal = 0;
        for (int i = 0; i < gas.size(); ++i) {
            currTotal += gas[i] - cost[i];
            if (currTotal < maxNeg) {
                maxNeg = currTotal;
                minInd = i + 1;
            }
        }
        if (minInd == gas.size() || currTotal < 0) {
            return -1;
        } else {
            return minInd;
        }
    }
};