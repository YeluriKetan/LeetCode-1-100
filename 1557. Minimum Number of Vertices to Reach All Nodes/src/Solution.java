import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        boolean[] bool = new boolean[n];
        for (List<Integer> curr: edges) {
            bool[curr.get(1)] = true;
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (bool[i]) {
                //
            } else {
                list.add(i);
            }
        }
        return list;
    }
}