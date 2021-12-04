import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;

class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        LinkedList<Integer> list = new LinkedList<>();
        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
        for (int i = 0; i < logs.length; i++) {
            HashSet<Integer> set;
            if (map.containsKey(logs[i][0])) {
                set = map.get(logs[i][0]);
            } else {
                list.add(logs[i][0]);
                set = new HashSet<>();
            }
            set.add(logs[i][1]);
            map.put(logs[i][0], set);
        }
        int[] arr = new int[k];
        for (Integer curr : list) {
            arr[map.get(curr).size() - 1]++;
        }
        return arr;
    }
}