import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        ArrayList<Integer> list = new ArrayList<>(List.of(2147483647));
        list.forEach(x -> System.out.println(sol.arrangeCoins(x)));
    }
}
