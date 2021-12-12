class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        long low = Math.min(a, b);
        long high = Math.max(a, b);
        int lcm = (a * b) / gcd(a, b);
        high *= n;

        long mid, count;
        while (low < high) {
            mid = low + (high - low) / 2;
            count = (mid / a) + (mid / b) - (mid / lcm);

            if (count == n) {
                if (mid % a == 0 || mid % b == 0) {
                    return (int) (mid % 1000000007);
                } else {
                    high = mid - 1;
                }
            } else if (count < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) (low % 1000000007);
    }

    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}
