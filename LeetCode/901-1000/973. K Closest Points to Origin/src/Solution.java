import java.util.PriorityQueue;

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> queue = new PriorityQueue<>();
        for (int[] point : points) {
            queue.add(new Point(point));
            if (queue.size() > k) {
                queue.poll();
            }
        }
        int[][] ans = new int[k][];
        for (int i = 0; i < k; i++) {
            ans[i] = queue.poll().cords;
        }
        return ans;
    }

    private static class Point implements Comparable<Point> {
        private int[] cords;
        private int length;

        private Point(int[] cords) {
            this.cords = cords;
            this.length = (cords[0] * cords[0]) + (cords[1] * cords[1]);
        }

        @Override
        public int compareTo(Point o) {
            return -Integer.compare(this.length, o.length);
        }
    }
}
