class Solution {
    public String[] divideString(String s, int k, char fill) {
        String[] ans = new String[(int) Math.ceil((double) s.length() / k)];
        s += String.valueOf(fill).repeat(ans.length * k - s.length());
        for (int i = 0; i < ans.length; i++) {
            ans[i] = s.substring(i * k, i * k + k);
        }
        return ans;
    }
}
