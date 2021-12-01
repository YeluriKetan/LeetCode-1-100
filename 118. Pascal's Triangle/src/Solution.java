import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new LinkedList<>();
        List<Integer> prevList = new ArrayList<>();
        prevList.add(1);
        list.add(prevList);
        for (int i = 2; i <= numRows; i++) {
            List<Integer> currList = new ArrayList<>();
            currList.add(1);
            for (int j = 1; j < i - 1; j++) {
                currList.add(prevList.get(j - 1) + prevList.get(j));
            }
            currList.add(1);
            list.add(currList);
            prevList = currList;
        }
        return list;
    }
}
