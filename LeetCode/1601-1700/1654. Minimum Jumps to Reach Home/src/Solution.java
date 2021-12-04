import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class Solution {

    private HashSet<Integer> set = new HashSet<>();
    private int forw, back, dest, max;
    private HashMap<ID, Integer> map = new HashMap<>();

    private class ID {
        private final int xCor;
        private final boolean dir;

        private ID(int xCor, boolean dir) {
            this.xCor = xCor;
            this.dir = dir;
        }

        @Override
        public int hashCode() {
            if (dir) {
                return xCor;
            } else {
                return 6000 + xCor;
            }
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof ID) {
                ID otherObj = (ID) obj;
                return this.xCor == otherObj.xCor && this.dir == otherObj.dir;
            } else {
                return false;
            }
        }
    }

    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        this.forw = a;
        this.back = b;
        this.dest = x;
        if (a < b) {
            this.max = 6000;
        } else {
            this.max = x + b;
        }
        for (int i = 0; i < forbidden.length; i++) {
            this.set.add(forbidden[i]);
        }
        BST();
        Integer ans = Math.min(map.getOrDefault(new ID(dest, true), Integer.MAX_VALUE),
                map.getOrDefault(new ID(dest, false), Integer.MAX_VALUE));
        if (ans == Integer.MAX_VALUE) {
            return -1;
        } else {
            return ans;
        }
    }

    private void BST() {
        Queue<ID> queue = new LinkedList<>();
        ID begin = new ID(0, true);
        queue.add(begin);
        queue.add(null);
        int count = 0;
        while (!queue.isEmpty()) {
            ID curr = queue.poll();
            if (curr == null) {
                count++;
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
                continue;
            }
            if (curr.xCor == dest) {
                map.put(curr, count);
                return ;
            }
            if (!map.containsKey(curr)) {
                map.put(curr, count);
                if (curr.xCor + forw <= max && !set.contains(curr.xCor + forw)) {
                    queue.add(new ID(curr.xCor + forw, true));
                }
                if (curr.dir) {
                    if (curr.xCor - back > 0 && !set.contains(curr.xCor - back)) {
                        queue.add(new ID(curr.xCor - back, false));
                    }
                }
            }
        }
    }
}