import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n < 3) {
            List<Integer> ans = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                ans.add(i);
            }
            return ans;
        }

        ArrayList<HashSet<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new HashSet<>());
        }
        for (int i = 0; i < n - 1; i++) {
            adjList.get(edges[i][0]).add(edges[i][1]);
            adjList.get(edges[i][1]).add(edges[i][0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (adjList.get(i).size() == 1) {
                queue.add(i);
            }
        }
        queue.add(null);
        int total = n;
        while (total > 2) {
            total -= queue.size() - 1;
            while (true) {
                Integer curr = queue.poll();
                if (curr == null) {
                    break;
                }
                Integer child = adjList.get(curr).iterator().next();
                adjList.get(child).remove(curr);
                if (adjList.get(child).size() == 1) {
                    queue.add(child);
                }
            }
            queue.add(null);
        }
        List<Integer> ans = new LinkedList<>();
        while (queue.peek() != null) {
            ans.add(queue.poll());
        }
        return ans;
    }
}
