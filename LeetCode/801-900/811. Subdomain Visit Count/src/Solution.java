import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        HashMap<String, Integer> map = new HashMap<>();
        String[] currArr;
        int count;
        String curr;
        for (int i = 0; i < cpdomains.length; i++) {
            currArr = cpdomains[i].split(" ");
            count = Integer.parseInt(currArr[0]);
            currArr = currArr[1].split("\\.");
            curr = currArr[currArr.length - 1];
            map.merge(curr, count, Integer::sum);
            for (int j = currArr.length - 2; j > -1; j--) {
                curr = currArr[j] + "." + curr;
                map.merge(curr, count, Integer::sum);
            }
        }
        List<String> list = new LinkedList<>();
        for (Map.Entry<String, Integer> currEntry: map.entrySet()) {
            list.add(currEntry.getValue() + " " + currEntry.getKey());
        }
        return list;
    }
}
