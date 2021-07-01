import java.util.HashMap;

class Solution {
    public boolean checkIfExist(int[] arr) {
        HashMap<Integer, Boolean> set = new HashMap(arr.length + 1, 1);
        for (int i = 0; i < arr.length; i++) {
            set.put(arr[i], true);
        }
        char count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                count++;
            } else {
                if (set.containsKey(2 * arr[i])) {
                    return true;
                } else {
                    //
                }
            }
        }
        return count > 1;
    }
}