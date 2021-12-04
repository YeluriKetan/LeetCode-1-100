class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int and = right;
        while (and > left) {
            and = and & and - 1;
        }
        return and & left;
    }
}
