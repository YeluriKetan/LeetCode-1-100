class Solution {
    public int numTeams(int[] rating) {
        int count = 0;
        int[] check = new int[rating.length];
        for (int i = rating.length - 1; i >= 0; i--) {
            int num = 0;
            for (int j = i; j < rating.length; j++) {
                if (rating[j] > rating[i]) {
                    num++;
                    if (check[j] > 0) {
                        count += check[j];
                    }
                }
            }
            check[i] = num;
        }
        for (int i = 0; i < rating.length; i++) {
            int num = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (rating[j] > rating[i]) {
                    num--;
                    if (check[j] < 0) {
                        count += -1 * check[j];
                    }
                }
            }
            check[i] = num;
        }
        return count;
    }
}