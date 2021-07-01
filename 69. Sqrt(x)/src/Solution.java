class Solution {
    public int mySqrt(int x) {
        int low = 0;
        int high = 46340;
        if (x == 1) {
            return x;
        }
        while(low < high) {
            int mid = low + (high - low)/2;
            if (mid * mid > x) {
                high = mid - 1;
            } else if (mid * mid == x) {
                return mid;
            } else if (high - low == 1) {
                if (high * high <= x) {
                    return high;
                } else {
                    return low;
                }
            } else {
                low = mid;
            }
        }
        return low;
    }
}