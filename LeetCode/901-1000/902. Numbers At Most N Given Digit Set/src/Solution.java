class Solution {
    public int atMostNGivenDigitSet(String[] digits, int n) {
        int[] arr = new int[10];
        arr[0] = 0;
        for (int i = 1, j = 0; i < arr.length; i++) {
            if (j < digits.length && digits[j].charAt(0) - '0' == i) {
                arr[i] = arr[i - 1] + 1;
                j++;
            } else {
                arr[i] = arr[i - 1];
            }
        }
        int total = 0;
        String curr = String.valueOf(n);
        int currPow = 1;
        for (int i = 1; i < curr.length(); i++) {
            currPow *= arr[9];
            total += currPow;
        }
        for (int i = 0; i < curr.length(); i++) {
            int currInt = curr.charAt(i) - '0';
            if (currInt == 0) {
                curr = null;
                break;
            }
            total += arr[currInt - 1] * currPow;
            currPow /= arr[9];
            if (arr[currInt] - arr[currInt - 1] != 1) {
                curr = null;
                break;
            }
        }
        return (curr == null) ? total : total + 1;
    }
}
