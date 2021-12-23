import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;

class Solution {

    private static final LinkedList<Integer> emptyList = new LinkedList<>();

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<>();
        for (int[] currArr: prerequisites) {
            LinkedList<Integer> currList = map.getOrDefault(currArr[1], new LinkedList<>());
            currList.add(currArr[0]);
            map.put(currArr[1], currList);
        }
        boolean[] done = new boolean[numCourses];
        Stack<Integer> stack = new Stack<>();
        int[] ans = new int[numCourses];
        int index = numCourses - 1;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < done.length; i++) {
            if (done[i]) {
                continue;
            }
            stack.add(i);
            set.clear();
            set.add(i);
            while (!stack.isEmpty()) {
                Integer curr = stack.peek();
                Integer currChild = map.getOrDefault(curr, emptyList).poll();
                if (currChild == null) {
                    stack.pop();
                    done[curr] = true;
                    ans[index--] = curr;
                    set.remove(curr);
                    continue;
                }
                if (set.contains(currChild)) {
                    return new int[0];
                }
                if (!done[currChild]) {
                    stack.push(currChild);
                    set.add(currChild);
                }
            }
        }
        return ans;
    }
}
