import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        int curr = 1;
        arr.add(curr);
        for (int i = 1; i < 31; i++) {
            curr *= 2;
            arr.add(curr);
        }
        System.out.println(arr.toString());
    }
}
