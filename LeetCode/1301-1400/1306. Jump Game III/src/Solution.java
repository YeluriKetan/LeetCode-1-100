import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public boolean canReach(int[] arr, int start) {
        boolean[] visited = new boolean[arr.length];
        boolean check = false;
        for (int j : arr) {
            if (j == 0) {
                check = true;
                break;
            }
        }
        if (!check) {
            return false;
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;
        queue.add(null);
        Integer curr;
        while (!queue.isEmpty()) {
            curr = queue.poll();
            if (curr == null) {
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
                continue;
            }
            if (arr[curr] == 0) {
                return true;
            }
            if (curr - arr[curr] > -1 && !visited[curr - arr[curr]]) {
                visited[curr - arr[curr]] = true;
                queue.add(curr - arr[curr]);
            }
            if (curr + arr[curr] < arr.length && !visited[curr + arr[curr]]) {
                visited[curr + arr[curr]] = true;
                queue.add(curr + arr[curr]);
            }
        }
        return false;
    }
}
