import java.util.LinkedList;

class Solution {
    public int[] processQueries(int[] queries, int m) {
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 1; i < m + 1; i++) {
            list.add(i);
        }
        int temp = 0;
        for (int i = 0; i < queries.length; i++) {
            temp = queries[i];
            queries[i] = list.indexOf(queries[i]);
            list.remove(queries[i]);
            list.addFirst(temp);
        }
        return queries;
    }
}