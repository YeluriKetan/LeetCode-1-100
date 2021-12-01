/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid = low + (high - low + 1) / 2;
        while (low < high) {
            if (high - low == 1) {
                return isBadVersion(low) ? low : high;
            }
            mid = low + (high - low + 1) / 2;
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
}
