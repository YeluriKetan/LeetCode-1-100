import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if (n < 3) {
            return n - 1;
        }
        if (arr[0] == arr[n - 1]) {
            return 1;
        }
        HashMap<Integer, ArrayList<Integer>> tracker = new HashMap<>();
        ArrayList<Integer> currList;
        currList = new ArrayList<>();
        currList.add(0);
        tracker.put(arr[0], currList);
        currList = new ArrayList<>();
        currList.add(n - 1);
        tracker.put(arr[n - 1], currList);
        for (int i = 1; i < n - 1; i++) {
            tracker.putIfAbsent(arr[i], new ArrayList<>());
            if (arr[i] != arr[i - 1] || arr[i] != arr[i + 1]) {
                tracker.get(arr[i]).add(i);
            }
        }
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(n - 1);
        queue.add(null);
        visited[n - 1] = true;
        int currInt;
        int count = 0;
        while (!queue.isEmpty()) {
            if (queue.peek() == null) {
                queue.poll();
                count++;
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
                continue;
            } else {
                currInt = queue.poll();
            }
            if (currInt > 0 && !visited[currInt - 1]) {
                if (currInt == 1) {
                    return count + 1;
                }
                visited[currInt - 1] = true;
                queue.add(currInt - 1);
            }
            if (currInt < n - 1 && !visited[currInt + 1]) {
                visited[currInt + 1] = true;
                queue.add(currInt + 1);
            }
            for (int currIntInList: tracker.get(arr[currInt])) {
                if (!visited[currIntInList]) {
                    if (currIntInList == 0) {
                        return count + 1;
                    }
                    visited[currIntInList] = true;
                    queue.add(currIntInList);
                }
            }
        }
        return count;
    }
}
