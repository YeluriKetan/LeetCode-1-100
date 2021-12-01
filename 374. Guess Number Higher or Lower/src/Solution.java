/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int mid;
        while (low < n) {
            mid = low + (n - low) / 2;
            switch (guess(mid)) {
            case -1:
                n = mid - 1;
                break;
            case 0:
                return mid;
            case 1:
                low = mid + 1;
                break;
            }
        }
        return low;
    }
}
