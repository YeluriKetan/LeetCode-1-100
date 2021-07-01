class Solution {
    public int countVowelStrings(int n) {
        int[] arr = {1,1,1,1,1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    arr[j] += arr[k];
                }
            }
        }
        return arr[0];
    }
}