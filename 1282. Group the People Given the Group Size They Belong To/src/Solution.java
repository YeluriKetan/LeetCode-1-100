import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List> arrayList = new LinkedList<>();
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<>(groupSizes.length, 1);
        for (int i = 0; i < groupSizes.length; i++) {
            if (map.get(groupSizes[i]) == null) {
                LinkedList<Integer> list = new LinkedList<>();
                list.add(i);
                if (groupSizes[i] == 1) {
                    arrayList.add(list);
                } else {
                    map.put(groupSizes[i], list);
                }
            } else {
                map.get(groupSizes[i]).add(i);
                if (map.get(groupSizes[i]).size() == groupSizes[i]) {
                    arrayList.add(map.get(groupSizes[i]));
                    map.replace(groupSizes[i], null);
                }
            }
        }
        return (List) arrayList;
    }
}