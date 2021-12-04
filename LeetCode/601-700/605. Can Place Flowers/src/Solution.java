class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = n;
        if (flowerbed.length == 1) {
            if (flowerbed[0] == 0) {
                return count - 1 < 1;
            } else {
                return count < 1;
            }
        }
        if (flowerbed.length == 2) {
            if (flowerbed[0] + flowerbed[1] == 0) {
                return count - 1 < 1;
            } else {
                return count < 1;
            }
        }
        if (flowerbed[0] + flowerbed[1] == 0) {
            flowerbed[0] = 1;
            count--;
        }
        for (int i = 1; i < flowerbed.length - 1; i++) {
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                count--;
            }
        }
        if (flowerbed[flowerbed.length - 2] + flowerbed[flowerbed.length - 1] == 0) {
            flowerbed[flowerbed.length - 1] = 1;
            count--;
        }
        return count < 1;
    }
}