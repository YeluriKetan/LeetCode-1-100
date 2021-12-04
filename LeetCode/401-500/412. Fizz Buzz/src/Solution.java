import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> list = new LinkedList<>();
        int count;
        for (int i = 1; i <= n; i++) {
            count = 0;
            if (i % 3 == 0) {
                count += 1;
            }
            if (i % 5 == 0) {
                count += 2;
            }
            switch (count) {
            case 0:
                list.add(String.valueOf(i));
                break;
            case 1:
                list.add("Fizz");
                break;
            case 2:
                list.add("Buzz");
                break;
            default:
                list.add("FizzBuzz");
            }
        }
        return list;
    }
}
