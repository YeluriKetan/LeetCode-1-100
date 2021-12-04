import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    q.add(new Pair(i, j));
                }
            }
        }
        q.add(null);
        Pair curr;
        int count = 0;
        while (!q.isEmpty()) {
            curr = q.poll();
            if (curr == null) {
                if (q.isEmpty()) {
                    break;
                } else {
                    q.add(null);
                    count++;
                    continue;
                }
            }
            if (curr.x > 0 && grid[curr.x - 1][curr.y] == 1) {
                grid[curr.x - 1][curr.y] = 2;
                q.add(new Pair(curr.x - 1, curr.y));
            }
            if (curr.x < grid.length - 1 && grid[curr.x + 1][curr.y] == 1) {
                grid[curr.x + 1][curr.y] = 2;
                q.add(new Pair(curr.x + 1, curr.y));
            }
            if (curr.y > 0 && grid[curr.x][curr.y - 1] == 1) {
                grid[curr.x][curr.y - 1] = 2;
                q.add(new Pair(curr.x, curr.y - 1));
            }
            if (curr.y < grid[0].length - 1 && grid[curr.x][curr.y + 1] == 1) {
                grid[curr.x][curr.y + 1] = 2;
                q.add(new Pair(curr.x, curr.y + 1));
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }

    private class Pair {
        public int x;
        public int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
