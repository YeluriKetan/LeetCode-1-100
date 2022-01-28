class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int pointer = 0;
        while (pointer < n - 1) {
            if (arr[pointer] < arr[pointer + 1]) {
                pointer++;
            } else {
                break;
            }
        }
        if (pointer == 0 || pointer == n - 1) {
            return false;
        }
        while (pointer < n - 1) {
            if (arr[pointer] > arr[pointer + 1]) {
                pointer++;
            } else {
                return false;
            }
        }
        return true;
    }
};