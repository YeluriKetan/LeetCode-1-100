class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        long total = (long) (rolls.length + n) * mean;
        for (int i = 0; i < rolls.length; i++) {
            total -= rolls[i];
        }
        if (total < n || total > 6 * n) {
            return new int[0];
        }
        int[] result = new int[n];
        int forAll = (int) total / n;
        int forSome = (int) total % n;
        for (int i = 0; i < n; i++) {
            if (forSome > 0) {
                result[i] = forAll + 1;
                forSome--;
            } else {
                result[i] = forAll;
            }
        }
        return result;
    }
}
