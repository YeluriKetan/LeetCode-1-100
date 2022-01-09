class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        sort(arr, arr + n, [&growTime](const int a, const int b) {
            return growTime[a] > growTime[b];
        });
        int pTime = 0;
        int gTime = -1;
        for (int i = 0; i < n; ++i) {
            pTime += plantTime[arr[i]];
            gTime = max(gTime, pTime + growTime[arr[i]]);
        }
        return gTime;
    }
};