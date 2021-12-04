import java.util.HashMap;
import java.util.TreeSet;

class Solution {
    public int[] avoidFlood(int[] rains) {
        int[] result = new int[rains.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < rains.length; i++) {
            if (rains[i] == 0) {
                result[i] = 1;
                set.add(i);
            } else {
                if (map.containsKey(rains[i])) {
                    Integer newI = set.higher(map.get(rains[i]));
                    if (newI == null) {
                        return new int[0];
                    } else {
                        result[newI] = rains[i];
                        set.remove(newI);
                    }
                }
                map.put(rains[i], i);
                result[i] = -1;
            }
        }
        return result;
    }
}