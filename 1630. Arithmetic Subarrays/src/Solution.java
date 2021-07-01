import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> list = new ArrayList<>();
        boolean curr;
        int[] copy;
        for (int i = 0; i < l.length; i++) {
            curr = true;
            copy = Arrays.copyOfRange(nums, l[i], r[i] + 1);
//            System.out.println("{" + l[i] + ", " + (r[i] - l[i] + 1) + "}");
            Arrays.sort(copy);
            int currDiff = copy[1] - copy[0];
//            System.out.println(currDiff);
            for (int j = 1; j < r[i] - l[i]; j++) {
//                System.out.println(copy[j + 1] - copy[j]);
                if (copy[j + 1] - copy[j] == currDiff) {

                } else {
                    curr = false;
                    break;
                }
            }
            list.add(curr);
        }
        return list;
    }
}