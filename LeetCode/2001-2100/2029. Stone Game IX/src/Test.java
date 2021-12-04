public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2,1};
        System.out.println(sol.stoneGameIX(arr));
    }
}
/*
    public boolean stoneGameIX(int[] stones) {
        int[] track = new int[3];
        for (int stone : stones) {
            track[stone % 3]++;
        }
        boolean bool1 = false;
        boolean bool2 = false;
        if (track[1] > 0) {
            bool1 = dp(track[0], track[1] - 1, track[2], 1, false);
        }
        if (track[2] > 0) {
            bool2 = dp(track[0], track[1], track[2] - 1, 2, false);
        }
        return bool1 || bool2;
    }
    private boolean dp(int num0, int num1, int num2, int sum, boolean turn) {
        boolean bool1 = false;
        boolean bool2 = false;
        switch (sum) {
        case 0:
            return turn;
        case 1:
            if (num0 + num1 == 0 && num2 > 0) {
                return !turn;
            }
            if (num0 > 0) {
                bool1 = dp(num0 - 1, num1, num2, sum, !turn);
            }
            if (num1 > 0) {
                bool2 = dp(num0, num1 - 1, num2, 2, !turn);
            }

            return bool1 || bool2;
        case 2:
            if (num0 + num2 == 0 && num1 > 0) {
                return !turn;
            }
            if (num0 > 0) {
                bool1 = dp(num0 - 1, num1, num2, sum, !turn);
            }
            if (num2 > 0) {
                bool2 = dp(num0, num1, num2 - 1, 1, !turn);
            }
            return bool1 || bool2;
        default:
            return false;
        }
    }
*/
