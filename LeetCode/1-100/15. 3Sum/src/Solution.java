import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.merge(nums[i], 1, Integer::sum);
        }
        List<List<Integer>> list = new LinkedList<>();
        Set<Map.Entry<Integer, Integer>> validSet = map.headMap(0).entrySet();
        for (Map.Entry<Integer, Integer> curr: validSet) {
            Set<Integer> currCurrSet = map
                    .subMap(curr.getKey(), true, (-curr.getKey()) / 2, true)
                    .keySet();
            for (Integer currI: currCurrSet) {
                if (curr.getKey().equals(currI) && map.get(currI) < 2) {
                    continue;
                }
                if (-curr.getKey() == 2 * currI && map.get(currI) < 2) {
                    continue;
                }
                if (map.containsKey(- curr.getKey() - currI)) {
                    LinkedList<Integer> newList = new LinkedList<>();
                    newList.add(curr.getKey());
                    newList.add(currI);
                    newList.add(-curr.getKey() - currI);
                    list.add(newList);
                }
            }
        }
        if (map.containsKey(0) && map.get(0) > 2) {
            LinkedList<Integer> newList = new LinkedList<>();
            newList.add(0);
            newList.add(0);
            newList.add(0);
            list.add(newList);
        }
        return list;
    }
}
