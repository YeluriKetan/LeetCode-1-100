class Solution {
    public int[] minOperations(String boxes) {
        char[] string = boxes.toCharArray();
        int[] arr = new int[boxes.length()];
        for (int i = 0; i < arr.length; i++) {
            if (string[i] == '1') {
                for (int j = 0; j < arr.length; j++) {
                    arr[j] = arr[j] + Math.abs(j - i);
                }
            }
        }
        return arr;
    }
}