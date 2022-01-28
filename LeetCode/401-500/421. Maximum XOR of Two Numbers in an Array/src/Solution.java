class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        TrieNode root = new TrieNode(32);
        for (int i = 0; i < nums.length; i++) {
            nums[i] = invertInt(nums[i]);
            root.add(nums[i]);
        }
        int maxXor = 0;
        int currXor;
        TrieNode currNode;
        int reqBit;
        for (int currInt: nums) {
            currXor = 0;
            currNode = root;
            for (int i = 0; i < 32; i++) {
                reqBit = 1 - (currInt & 1);
                currInt >>= 1;
                currXor <<= 1;
                if (currNode.children[reqBit] != null) {
                    currXor += 1;
                    currNode = currNode.children[reqBit];
                } else if (currNode.children[1 - reqBit] != null) {
                    currNode = currNode.children[1 - reqBit];
                } else {
                    currXor = 0;
                    break;
                }
            }
            maxXor = Math.max(maxXor, currXor);
        }
        return maxXor;
    }

    private int invertInt(int x) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans += (x & 1);
            x >>= 1;
        }
        return ans;
    }

    private class TrieNode {
        private TrieNode[] children;
        private int index;

        private TrieNode(int index) {
            this.index = index;
            this.children = new TrieNode[2];
        }

        private void add(int curr) {
            if (index <= 0) {
                return;
            }
            int index = curr & 1;
            if (children[index] == null) {
                children[index] = new TrieNode(this.index - 1);
            }
            curr >>>= 1;
            children[index].add(curr);
        }
    }
}
