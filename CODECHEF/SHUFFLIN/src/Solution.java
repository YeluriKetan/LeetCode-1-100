import java.util.*;

public class Solution {
    public int shufflingParities(int[] arr) {
        int even = 0;
        for (int i = 0; i < arr.length; i++) {
            if ((arr[i] % 2 == 0)) {
                even++;
            }
        }
        return Math.min(arr.length / 2, arr.length - even) + Math.min(arr.length - arr.length / 2, even);
    }

    public static void main(String[] args) {
        int[] arr = {1,1,1,1,2,2,2,2};
        System.out.println(new Solution().shufflingParities(arr));
        System.out.println(Arrays.toString(args));
    }
}
