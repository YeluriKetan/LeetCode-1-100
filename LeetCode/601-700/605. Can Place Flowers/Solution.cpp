class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = flowerbed.size();
        int count = 1;
        for (int i = prev - 1; i > -1; --i) {
            if (n < 1) {
                return true;
            }
            if (flowerbed[i]) {
                n -= (count - 1) / 2;
                count = 0;
            } else {
                count++;
            }
        }
        n -= (count / 2);
        return n < 1;
    }
};