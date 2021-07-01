public class Test {
    public static void main(String[] args) {
        String str1 = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
        String str2 = "aaaba";
        Solution sol = new Solution();
        System.out.println(sol.maxRepeating(str1, str2));
    }
}
