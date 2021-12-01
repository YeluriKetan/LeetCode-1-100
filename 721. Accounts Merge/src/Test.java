import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        List<List<String>> list = new ArrayList<>();
        String[][] arr = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
        for (String[] strings : arr) {
            list.add(new ArrayList<>(Arrays.asList(strings)));
        }
        for (List<String> strings : list) {
            System.out.println(strings);
        }
        list = sol.accountsMerge(list);
        System.out.println("");
        for (List<String> strings : list) {
            System.out.println(strings);
        }
    }
}
