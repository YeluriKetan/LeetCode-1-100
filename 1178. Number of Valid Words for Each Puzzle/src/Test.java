import java.util.List;

public class Test {
    public static void main(String[] args) {
        String[] words = {"aaaa","asas","able","ability","actt","actor","access"};
        String[] puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
        Solution sol = new Solution();
        List<Integer> list = sol.findNumOfValidWords(words, puzzles);
        System.out.println(list.toString());
    }
}
