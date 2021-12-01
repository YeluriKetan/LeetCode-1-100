class Solution {
    public int[] plusOne(int[] digits) {
        int index = digits.length - 1;
        while (index >= 0) {
            if (digits[index] != 9) {
                digits[index]++;
                return digits;
            }
            digits[index] = 0;
            index--;
        }
        int[] arr = new int[digits.length + 1];
        arr[0] = 1;
        System.arraycopy(digits, 0, arr, 1, digits.length);
        return arr;
    }
}
