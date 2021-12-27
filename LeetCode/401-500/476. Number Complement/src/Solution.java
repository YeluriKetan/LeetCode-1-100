class Solution {
    public int findComplement(int num) {
        int ans = ~num;
        int and = 0;
        while (num > 0) {
            and <<= 1;
            and += 1;
            num >>>= 1;
        }
        return ans & and;
    }
}
