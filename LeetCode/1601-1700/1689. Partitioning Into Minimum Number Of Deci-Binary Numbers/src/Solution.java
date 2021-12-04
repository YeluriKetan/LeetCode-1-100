class Solution {
    public int minPartitions(String n) {
        char[] arr = n.toCharArray();
        int max = -1;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(arr[i], max);
        }
        return max - 48;
    }
}