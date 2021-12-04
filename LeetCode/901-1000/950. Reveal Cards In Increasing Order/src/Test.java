public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {17,13,11,2,3,5,7};
        int[] newArr = sol.deckRevealedIncreasing(arr);
        for (int i = 0; i < newArr.length; i++) {
            System.out.print(newArr[i] + ",");
        }
    }
}
