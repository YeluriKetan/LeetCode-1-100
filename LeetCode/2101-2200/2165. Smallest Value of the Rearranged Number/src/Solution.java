import java.util.Arrays;

class Solution {
    public long smallestNumber(long num) {
        boolean isNeg = num < 0;
        char[] arr = String.valueOf(Math.abs(num)).toCharArray();
        Arrays.sort(arr);
        num = 0;
        if (isNeg) {
            for (int i = arr.length - 1; i > -1; i--) {
                num *= 10;
                num += arr[i] - '0';
            }
            num *= -1;
        } else {
            int numOfZeroes = 0;
            int index = 0;
            while (index < arr.length && arr[index] == '0') {
                numOfZeroes++;
                index++;
            }
            if (index == arr.length) {
                return num;
            }
            num = arr[index++] - '0';
            for (int i = 0; i < numOfZeroes; i++) {
                num *= 10;
            }
            while (index < arr.length) {
                num *= 10;
                num += arr[index++] - '0';
            }
        }
        return num;
    }
}
