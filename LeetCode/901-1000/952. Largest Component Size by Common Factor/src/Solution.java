import java.util.HashMap;

class Solution {
    private static HashMap<Integer, Integer> parentMap;

    public Solution() {
        parentMap = new HashMap<>();
    }

    public int largestComponentSize(int[] nums) {
        parentMap.clear();

        for (int i = 0; i < nums.length; i++) {
            for (int j = 2; j <= Math.sqrt(nums[i]); j++) {
                if (nums[i] % j == 0) {
                    makeDescendants(nums[i], j);
                    makeDescendants(nums[i], nums[i] / j);
                }
            }
        }

        int currParent;
        int maxCount = Integer.MIN_VALUE;
        HashMap<Integer, Integer> countMap = new HashMap<>();
        for (Integer currKey: nums) {
            currParent = findHighestAncestor(currKey);
            maxCount = Math.max(maxCount, 1 + countMap.getOrDefault(currParent, 0));
            countMap.put(currParent, 1 + countMap.getOrDefault(currParent, 0));
        }

        return maxCount;
    }

    private int findHighestAncestor(int x) {
        if (!parentMap.containsKey(x)) {
            return x;
        }
        parentMap.put(x, findHighestAncestor(parentMap.get(x)));
        return parentMap.get(x);
    }

    private void makeDescendants(int x, int y) {
        int parentX = findHighestAncestor(x);
        int parentY = findHighestAncestor(y);
        if (parentX != parentY) {
            parentMap.put(parentY, parentX);
        }
    }
}
