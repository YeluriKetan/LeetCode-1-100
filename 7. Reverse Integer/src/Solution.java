class Solution {
    public int reverse(int x) {
        int y = Math.abs(x);
        int newX = 0;
        while(y > 0) {
            newX *= 10;
            newX += (y % 10);
            y /= 10;
            if (newX > Integer.MAX_VALUE / 10 && y > 0) {
                return 0;
            }
        }
        if (x > 0) {
            return newX;
        } else {
            return -newX;
        }
    }
}
